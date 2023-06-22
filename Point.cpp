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
        const double earthRadiusKm = 6371;
        const double PI = acos(-1);

        double dLat = (P.x - x) * PI / 180;
        double dLon = (P.y - y) * PI / 180;

        double lat1 = P.x * PI / 180;
        double lat2 = x * PI / 180;

        double a = sin(dLat/2) * sin(dLat/2) +
                   sin(dLon/2) * sin(dLon/2) * cos(lat1) * cos(lat2);
        double c = 2 * atan2(sqrt(a), sqrt(1-a));
        return earthRadiusKm * c;
    }


