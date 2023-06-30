//
// Created by raduc on 19.04.2023.
//

#ifndef OOP_RATING_H
#define OOP_RATING_H


#include <ostream>

class Rating {
    float val;
    int numberOfRatings;
public:
    Rating();
    explicit Rating(float val);
    Rating(const Rating &other);

    Rating& operator=(const Rating& other);
    void addRating(int newRating);
    void addRating(const Rating &newRating);
    float getVal() const;

    friend std::ostream &operator<<(std::ostream &os, const Rating &rating);
};


#endif //OOP_RATING_H
