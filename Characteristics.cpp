//
// Created by raduc on 19.04.2023.
//


#include "Characteristics.h"

float Characteristics::getMatching(const Characteristics &c) {
    float ret = 0;
    for (int i = 0; i < 3; i++)
        ret += this->characteristics[i].getVal() * c.characteristics[i].getVal();
    return ret;
}

void Characteristics::updateCharacteristics(const Characteristics &characteristics, int multiplier) {
    for (int i = 0; i < 4; i++)
        if (characteristics.characteristics[i].getVal() != 0)
        for (int j = 0; j < multiplier; j++)
            this->characteristics[i].addRating(characteristics.characteristics[i].getVal());
}

Characteristics::Characteristics(int a, int b, int c, int d) {
    characteristics[0].addRating(a);
    characteristics[1].addRating(b);
    characteristics[2].addRating(c);
    characteristics[3].addRating(d);
}