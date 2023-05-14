 //
// Created by raduc on 19.04.2023.
//

#ifndef OOP_POINT_H
#define OOP_POINT_H

#include <iostream>


class Point {
     float x, y;
 public:
     Point();
     Point(float x, float y);
     Point(const Point & other);
     ~Point();

     Point& operator=(const Point &other);

     float Distance(const Point &P) const;

     friend std::ostream &operator<<(std::ostream &os, const Point &point) {
         os << "x: " << point.x << " y: " << point.y;
         return os;
     }

 };

#endif //OOP_POINT_H
