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

void User::updateCharacteristics(Characteristics &characteristics, int multiplier) {
    this->characteristics.updateCharacteristics(characteristics, multiplier);
}

const Characteristics & User::getCharacteristics() {
    return characteristics;
}
