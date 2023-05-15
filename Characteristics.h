//
// Created by raduc on 19.04.2023.
//

#ifndef OOP_CHARACTERISTICS_H
#define OOP_CHARACTERISTICS_H

#include <array>
#include <ostream>
#include "Rating.h"


class Characteristics {
private:
    std::array<Rating, 4> characteristics = {Rating(0), Rating(0), Rating(0), Rating(0)};
public:
    Characteristics() = default;
    Characteristics(int a, int b, int c, int d);

    float getMatching(const Characteristics &c);

    void updateCharacteristics(const Characteristics &characteristics, int multiplier);
};

#endif //OOP_CHARACTERISTICS_H

