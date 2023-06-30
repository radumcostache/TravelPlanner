//
// Created by raduc on 19.04.2023.
//

#include "Attraction.h"

Attraction::Attraction() : name(), rating(), chr(1, 1, 1, 1) {std::cerr << "Successful use of Attraction constructor";}
Attraction::Attraction(const std::string &name, const Rating &rating)
        : name(name), rating(rating), chr(1, 1, 1, 1) {std::cerr << "Successful use of Attraction constructor";}

const Rating & Attraction::getRating()  const{
    return rating;
}

/*const Point & getLocation() {
    return location;
}*/


const std::string &Attraction::getName() const {
    return name;
}

const Characteristics<char> &Attraction::getChr() const {
    return chr;
}

