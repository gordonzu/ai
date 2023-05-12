// xy_environment.cpp
// gordonyx 5-12-2023

#include "environment/xyenv/xy_environment.h"
#include <stdexcept>

XYEnvironment::XYEnvironment(int w, int h) : width{w}, height{h} {
    if (w < 1 || h < 1) 
        throw std::runtime_error("Invalid parameter values");

    for (int x = 1; x <= width; ++x) {
        for (int y = 1; y <= height; ++y) {
            agent_map.emplace_back(
                    XYLocation{x,y}, EnvVec());
        }
    }
    binary_sort_map();
}

XYLocation& XYEnvironment::get_location(const EnvPtr obj) {
    for (auto& x : get_map()) {
        if (std::find(x.second.begin(), 
                    x.second.end(), obj) 
                != x.second.end()) { 
            return x.first;
        }
    }
    return xyNull;
}

void XYEnvironment::add(const EnvPtr obj, const XYLocation& xy) {
    check_object(obj);
    check_map_for_location(xy).emplace_back(obj);
    if (!obj->is_wall()) 
        add_agent(obj);
    add_environment_object(obj);
}

size_t XYEnvironment::objects_at_location(const XYLocation& xy) {
    return has_xy(xy)->second.size();
}

size_t XYEnvironment::matrix_size() {
    return agent_map.size();
}

void XYEnvironment::move_absolute(const EnvPtr obj, const XYLocation& xy) {
    add(obj, xy);
}

void XYEnvironment::move_object(const EnvPtr obj, const XYLocation::Direction& dir) {
    XYLocation tmp = get_location(obj);

    if (tmp != xyNull) {
        tmp = tmp.location_at(dir);
        if (!(is_blocked(tmp))) {
            add(obj, tmp);
        }
    }
}

bool XYEnvironment::is_blocked(const XYLocation& xy) {
    return blocked(xy);
}

EnvVec& XYEnvironment::get_objects_near(const EnvPtr obj, int rad) {
    nearObjs.clear();
    auto xy = get_location(obj);

    for (auto& v : get_map()) {
        if( in_radius(rad, xy, v.first)) {
            nearObjs.insert(nearObjs.end(), 
                v.second.begin(), 
                v.second.end());
        }
    }

    auto it = std::find(nearObjs.begin(), nearObjs.end(), obj);
    if (it != nearObjs.end()) nearObjs.erase(it);
    return nearObjs;
}

void XYEnvironment::make_perimeter(int x) {
    EnvVec walls;
    std::vector<XYLocation> locations;

    for (int i = 1; i <=x; ++i) {
        walls.emplace_back(std::make_unique<Wall>());
        locations.emplace_back(XYLocation{1,i});
        walls.emplace_back(std::make_unique<Wall>());
        locations.emplace_back(XYLocation{i,1});
    }

    for (int i = 1; i <=x; ++i) {
        walls.emplace_back(std::make_unique<Wall>());
        locations.emplace_back(XYLocation{i,x});
        walls.emplace_back(std::make_unique<Wall>());
        locations.emplace_back(XYLocation{x,i});
    }

    for (unsigned i = 0; i < walls.size(); ++i) {
        add(walls[i], locations[i]);
    }
}

void XYEnvironment::binary_sort_map() {
    std::sort(get_map().begin(),
        get_map().end(),
        [](auto& left, auto& right) {
            return left.first < right.first;
    });  
}

bool XYEnvironment::blocked(const XYLocation& xy) {
    for (auto& eo : check_map_for_location(xy)) {
        if (eo->is_wall()) 
            return true;
    }
    return false;
}

bool XYEnvironment::in_radius(int rad, const XYLocation& a, const XYLocation& b) {
    int xdiff = a.getx() - b.getx();
    int ydiff = a.gety() - b.gety();
    return std::sqrt((xdiff * xdiff) + (ydiff * ydiff)) <= rad;
}

Map::iterator XYEnvironment::has_xy(const XYLocation& loc) {
    itv = std::find_if(
        get_map().begin(),
        get_map().end(),
        [loc](std::pair<XYLocation, EnvVec>& mypair) {
            return (mypair.first == loc);
    });
    return itv;
}

Map& XYEnvironment::get_map() {
    return agent_map;
}

void XYEnvironment::check_object(const EnvPtr obj) {
    for (auto& x : agent_map) {  
        if (its = x.second.begin(); its != x.second.end()) {
            if (**its == *obj) {
                x.second.erase(its);
                break;
            }
            ++its;
        }
    }
}

EnvVec& XYEnvironment::check_map_for_location(const XYLocation& xy) {
    if (has_xy(xy) != get_map().end()) {
        return itv->second;
    }

    if(check_matrix_dimensions(xy)) {
        agent_map.emplace_back(xy, EnvVec());
    } else {
        flag = true;
    }

    binary_sort_map();
    return has_xy(xy)->second;
}

bool XYEnvironment::check_matrix_dimensions(const XYLocation& xy) {
    itv = std::prev(get_map().end());

    if (itv->first < xy) {
        flag = false;
        grow_matrix(xy);
    }
    return flag;
}

void XYEnvironment::grow_matrix(const XYLocation& xy) {
    int new_width = 0;
    int new_height = 0;

    if ((xy.getx() - itv->first.getx()) > 0)
        new_width = xy.getx();

    if (( xy.gety() - itv->first.gety()) > 0)
        new_height = xy.gety();

    if (new_width) 
        add_rows(new_width);

    if (new_height) 
        add_columns(new_height);
}

void XYEnvironment::add_rows(int new_width) {
    for (int i = (width + 1); i <= new_width; ++i) {
        for (int ii = 1; ii <= height; ++ii) {
            agent_map.emplace_back(XYLocation{i,ii}, EnvVec());
        }
    }
    width = new_width;
}

void XYEnvironment::add_columns(int new_height) {
    for (int i = 1; i <= width; ++i) {
        for (int ii = (height + 1); ii <= new_height; ++ii) {
            agent_map.emplace_back(XYLocation{i,ii}, EnvVec());
        }
    }
    height = new_height;
}

void XYEnvironment::int_map_locations() {
    for (const std::pair<XYLocation, EnvVec>& p : agent_map)
        std::cout << "Location: " << p.first << std::endl; 
}

int XYEnvironment::get_width() {
    return width;
}

int XYEnvironment::get_height() {
    return height;
}





















