//
// Created by raduc on 19.04.2023.
//



#include "Destination.h"
#include "Characteristics.h"

Destination::Destination(const std::string &name, const std::string &description, const Point &location,
                         const std::vector<Attraction> &attraction,
                         const Characteristics &characteristics) : name(name), description(description), location(location),
                                                                   attraction(attraction),
                                                                   characteristics(characteristics) {
    Rating rt;
    for (auto it:attraction)
        rt.addRating(it.getRating().getVal());
    this->attractionRating = rt;
    std::cerr << "Successful use of Destination constructor";
}

Destination::~Destination() {
    std::cerr << "Successful use of Destination constructor";
}

Destination &Destination::operator=(const Destination &other) {
    name = other.name;
    description = other.description;
    location = other.location;
    attraction = other.attraction;
    attractionRating = other.attractionRating;
    return *this;
}

/*void Destination::addAttraction(const Attraction &A) {
    attraction.push_back(A);
    attractionRating.addRating(A.getRating());
}*/

std::string &Destination::getName() {
    return name;
}

std::vector<Attraction> &Destination::topByReviews() {
    sort(attraction.begin(), attraction.end(), [](const Attraction & A, const Attraction & B) {return A.getRating().getVal() > B.getRating().getVal();});
    return attraction;
}

float Destination::getMatching(Characteristics &prio) {
    return prio.getMatching(characteristics);
}

Destination Destination::bestMatch(const std::vector<Destination> &v, Characteristics prio) {
    float best = 0;
    Destination ret;
    for (auto it:v) {
        float curr = it.getMatching(prio);
        if (curr > best) {
            best = curr;
            ret = it;
        }
    }
    return ret;
}

const std::string &Destination::getDescription() const {
    return description;
}

const Point &Destination::getLocation() const {
    return location;
}
