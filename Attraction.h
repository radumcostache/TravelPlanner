//
// Created by raduc on 19.04.2023.
//

#ifndef OOP_ATTRACTION_H
#define OOP_ATTRACTION_H

#include <iostream>
#include "Point.h"
#include "Rating.h"
#include "Characteristics.h"

class Attraction {
    std::string name;
    Rating rating;
    Characteristics<char> chr;
public:
    Attraction();
    Attraction(const std::string &name, const Rating &rating);
    Attraction(const Attraction & t) = default;
    ~Attraction() = default;
    Attraction &operator =(const Attraction &other) = default;

    const Characteristics<char> &getChr() const;

    const Rating &getRating() const;
    const std::string &getName() const;


};

#endif //OOP_ATTRACTION_H
