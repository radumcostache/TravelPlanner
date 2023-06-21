//
// Created by raduc on 07.05.2023.
//

#ifndef OOP_USER_H
#define OOP_USER_H

#include <vector>
#include "Characteristics.h"
#include "Point.h"

// Singleton
class User {
    Point location;
    Characteristics<int> chr;
    std::vector <double> answers;
    User() = default;
public:
    User(const User &) = delete;
    User &operator=(const User &) = delete;
    static User &getUser();
    void updateCharacteristics(const Characteristics<int> &extra, int multiplier);
    Point getLocation();
    const Characteristics<int> & getCharacteristics();
    void addAnswer(double answer);
    void updateLocation(double lati, double longi);

    const std::vector<double> &getAnswers() const;
};


#endif //OOP_USER_H
