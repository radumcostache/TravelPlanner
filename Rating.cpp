//
// Created by raduc on 19.04.2023.
//

#include "Rating.h"
#include <iostream>

Rating::Rating(): val(1), numberOfRatings(0) {std::cout << "";};

Rating::Rating(float val): val(val), numberOfRatings(1) {
    std::cerr << "";
};
Rating::Rating(const Rating &other) : val(other.val), numberOfRatings(other.numberOfRatings) {
    std::cerr << "";
}

Rating& Rating::operator=(const Rating& other) {
    val = other.val;
    numberOfRatings = other.numberOfRatings;
    return *this;
}
void Rating::addRating(int newRating) {
    if(newRating == 0)
        return;
    if (val == 0) {
        val = (float)newRating;
        numberOfRatings = 1;
        return;
    }
    val *= (float)numberOfRatings;
    val += (float)newRating;
    numberOfRatings++;
    val /= (float)numberOfRatings;
}
void Rating::addRating(const Rating &newRating) {
    if (newRating.val == 0)
        return;
    if (val == 0) {
        val = newRating.val;
        numberOfRatings = newRating.numberOfRatings;
        return;
    }
    val *= (float)numberOfRatings;
    val += newRating.getVal();
    numberOfRatings++;
    val /= (float)numberOfRatings;
}
float Rating::getVal() const {
    return val;
}

std::ostream &operator<<(std::ostream &os, const Rating &rating) {
    os << "val: " << rating.val << " numberOfRatings: " << rating.numberOfRatings;
    return os;
}


