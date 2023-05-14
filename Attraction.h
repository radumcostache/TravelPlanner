//
// Created by raduc on 19.04.2023.
//

#ifndef OOP_ATTRACTION_H
#define OOP_ATTRACTION_H

#include <iostream>
#include "Point.h"
#include "Rating.h"

class Attraction {
    std::string name;
    Rating rating;
public:
    Attraction();
    Attraction(const std::string &name, const Rating &rating);
    Attraction(const Attraction & t) = default;
    ~Attraction();
    Attraction &operator =(const Attraction &other) = default;
    const Rating &getRating() const;
    const std::string &getName() const;


};

#endif //OOP_ATTRACTION_H
