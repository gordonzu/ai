// gordon zuehlke 2/22/20

#ifndef XY_ENVIRONMENT_H
#define XY_ENVIRONMENT_H

#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>                       
#include "wall.h"
#include "environment/environment.h"               
#include "util/xy_location.h"

class Wall;

using EnvPtr = std::shared_ptr<EnvironmentObj>;
using EnvVec = std::vector<EnvPtr>;
using Map = std::vector<std::pair<XYLocation, EnvVec>>;

class XYEnvironment : public env::Environment {
public:
    XYEnvironment(int w, int h); 

    XYLocation& get_location(const EnvPtr obj);
    void add(const EnvPtr obj, const XYLocation& xy); 
    size_t objects_at_location(const XYLocation& xy);
    size_t matrix_size();
    void move_absolute(const EnvPtr obj, const XYLocation& xy);
    void move_object(const EnvPtr obj, const XYLocation::Direction& dir);
    bool is_blocked(const XYLocation& xy); 
    EnvVec& get_objects_near(const EnvPtr obj, int rad);
    void make_perimeter(int x); 

private:
    void binary_sort_map();
    bool blocked(const XYLocation& xy);
    bool in_radius(int rad, const XYLocation& a, const XYLocation& b);
    Map::iterator has_xy(const XYLocation& loc);
    Map& get_map();
    void check_object(const EnvPtr obj);
    EnvVec& check_map_for_location(const XYLocation& xy);
    bool check_matrix_dimensions(const XYLocation& xy);
    void grow_matrix(const XYLocation& xy);
    void add_rows(int new_width);
    void add_columns(int new_height);
    void int_map_locations();
    int get_width();
    int get_height();

    Map agent_map;
    Map::iterator itv;
    EnvVec::iterator its;
    EnvVec nearObjs;
    int width{0};
    int height{0}; 
    XYLocation xyNull{0,0};
    bool flag{true};
};
#endif
