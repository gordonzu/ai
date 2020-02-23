// gordon zuehlke 2/22/20

#ifndef XYLOCATION_H 
#define XYLOCATION_H

#include <iostream>
#include <memory>

//TODO: why do the direction methods return a copy of a local stack object?
//TODO: change them to return a unique pointer

class XYLocation {
public:
    enum class Direction: unsigned short{ NORTH, SOUTH, EAST, WEST };

    XYLocation() {}
    XYLocation(int x, int y): x_{x}, y_{y} {}
    ~XYLocation() {}

    XYLocation(const XYLocation& other) {
        x_ = other.x_;
        y_ = other.y_;
    }

    XYLocation(XYLocation& other) {
        x_ = other.x_;
        y_ = other.y_;
    }

    void print() {
        std::cout << "{" << x_ << ", " << y_ << "}" <<  std::endl;
    }

    int getx() const {
        return x_;
    }

    int gety() const {
        return y_;
    }

    XYLocation& operator=(const XYLocation& rhs) {
        if (&rhs != this) {
            x_ = rhs.x_;
            y_ = rhs.y_;
        }
        return *this;
    }

    bool operator<(const XYLocation& rhs) const {
        if ((x_ < rhs.x_) || (y_ < rhs.y_))     
            return true;
        return false;
    } 

    bool operator==(const XYLocation& rhs) const  {
            return ((x_ == rhs.x_) && (y_ == rhs.y_));
    }

    bool operator!=(const XYLocation& rhs) const  {
            return ((x_ != rhs.x_) || (y_ != rhs.y_));
    }

    XYLocation west() {
        XYLocation tmpxy{x_ - 1, y_};
        return tmpxy;
    }

    XYLocation east() {
        XYLocation tmpxy{x_ + 1, y_};
        return tmpxy;
    }

    XYLocation north() {
        XYLocation tmpxy{x_, y_ -1};
        return tmpxy;
    }

    XYLocation south() {
        XYLocation tmpxy{x_, y_ + 1};
        return tmpxy;
    }

    XYLocation right() {
        return east();
    }

    XYLocation left() {
        return west();
    }

    XYLocation up() {
        return north();
    }

    XYLocation down() {
        return south();
    }

    XYLocation location_at(const Direction& direction) {
        XYLocation xy;
        try {
            switch (direction) {
                case     Direction::NORTH:
                         xy = north();
                         break;
                case     Direction::SOUTH:
                         xy = south();
                         break;
                case     Direction::EAST:
                         xy = east();
                         break;
                case     Direction::WEST:
                         xy = west();
                         break;
                default: throw std::runtime_error("Unknown direction...");
            } 
        }
        catch(std::exception const& e) {
            std::cerr << "Exception: " << e.what() << "\n";
        }
        return xy;
    }

    friend std::ostream& operator<<(std::ostream& out, const XYLocation& xy) {
        out << "{" << xy.x_ << ", " << xy.y_ << "}";
        return out;
    }

private:
    int x_;
    int y_;
};
#endif




/*        XYLocation();
    XYLocation(int x, int y);
    ~XYLocation();
    XYLocation(const XYLocation& other);
    XYLocation(XYLocation& other);

    XYLocation& operator=(const XYLocation& rhs);
    bool operator==(const XYLocation& rhs) const; 
    bool operator<(const XYLocation& rhs) const;
    bool operator!=(const XYLocation& rhs) const;
    friend std::ostream& operator<<(std::ostream& out, const XYLocation& xy);

    void print();
    enum class Direction: unsigned short{ NORTH, SOUTH, EAST, WEST };

    int getx() const;
    int gety() const;

    XYLocation west();
    XYLocation east();
    XYLocation north();
    XYLocation south();
    XYLocation left();
    XYLocation right();
    XYLocation up();
    XYLocation down();
    XYLocation location_at(const Direction& direction);

private:
    int x_;
    int y_;
*/
