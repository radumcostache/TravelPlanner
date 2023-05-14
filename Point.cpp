//
// Created by raduc on 19.04.2023.
//

#include "Point.h"
#include <cmath>
#include <ctgmath>

    Point::Point() : x(0), y(0) {std::cerr << "Successful use of Point constructor";}
    Point::Point(float x, float y) : x(x), y(y) {std::cerr << "Successful use of Point constructor";}
    Point::Point(const Point & other) : x(other.x), y(other.y) {std::cerr << "Successful use of Point constructor";}
    Point::~Point() {
        std::cerr << "Successful use of Point destructor";
    }

    Point& Point::operator=(const Point &other) {
        x = other.x;
        y = other.y;
        return *this;
    }

    float Point::Distance(const Point &P) const {
        return acos(sin(x)*sin(P.x)+cos(x)*cos(P.x)*cos(P.y-y))*6371;
    }


