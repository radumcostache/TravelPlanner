//
// Created by raduc on 19.04.2023.
//

#include "Attraction.h"

Attraction::Attraction() : name(), rating() {std::cerr << "Successful use of Attraction constructor";}
Attraction::Attraction(const std::string &name, const Rating &rating)
        : name(name), rating(rating) {std::cerr << "Successful use of Attraction constructor";}
Attraction::~Attraction() {
    std::cerr << "Successful use of Attraction destructor";
}

const Rating & Attraction::getRating()  const{
    return rating;
}

/*const Point & getLocation() {
    return location;
}*/


const std::string &Attraction::getName() const {
    return name;
}

