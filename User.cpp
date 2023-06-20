//
// Created by raduc on 07.05.2023.
//

#include "User.h"

Point User::getLocation() {
    return location;
}

void User::updateLocation(double lati, double longi) {
    location = Point(lati, longi);
}

void User::updateCharacteristics(const Characteristics &extra, int multiplier) {
    chr.updateCharacteristics(extra, multiplier);
}

const Characteristics & User::getCharacteristics() {
    return chr;
}

void User::addAnswer(double answer) {
    answers.push_back(answer);
}

User &User::getUser() {
    static User user;
    return user;
}

const std::vector<double> &User::getAnswers() const {
    return answers;
}
