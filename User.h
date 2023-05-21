//
// Created by raduc on 07.05.2023.
//

#ifndef OOP_USER_H
#define OOP_USER_H

#include <vector>
#include "Characteristics.h"
#include "Point.h"


class User {
    Point location;
    Characteristics chr;
    std::vector <double> answers;
public:
    void updateCharacteristics(const Characteristics &extra, int multiplier);
    Point getLocation();
    const Characteristics & getCharacteristics();
    void addAnswer(double answer);
    void updateLocation(double lati, double longi);

    const std::vector<double> &getAnswers() const;
};


#endif //OOP_USER_H
