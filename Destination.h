//
// Created by raduc on 19.04.2023.
//

#ifndef OOP_DESTINATION_H
#define OOP_DESTINATION_H

#include "Point.h"
#include "Rating.h"
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include "Destination.h"
#include "Attraction.h"
#include "Characteristics.h"

class Destination {
    std::string name;
    std::string description;
    Point location;
    std::vector<Attraction> attraction;
    Rating attractionRating;
    Characteristics characteristics;
    static double MAX_DISTANCE;
public:
    static void setMaxDistance(double maxDistance);

    Destination() = default;
    Destination(const std::string &name, const std::string &description, const Point &location,
                const std::vector<Attraction> &attraction,
                const Characteristics &characteristics);
    Destination(const Destination &) = default;
    ~Destination();

    Destination& operator=(const Destination & other);
    //void addAttraction(const Attraction & A);
    float getMatching(Characteristics & prio);

    const std::string &getDescription() const;
    const Point &getLocation() const;

    static Destination bestMatch(const std::vector<Destination> &v,  Characteristics prio, const Point &location);
    std::string & getName();
    std::vector<Attraction> &topByReviews();

};

#endif //OOP_DESTINATION_H
