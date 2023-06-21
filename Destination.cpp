//
// Created by raduc on 19.04.2023.
//



#include "Destination.h"
#include "Characteristics.h"
#include "FrameErr.h"

Destination::Destination(const std::string &name, const std::string &description, const Point &location,
                         const std::vector<Attraction> &attraction,
                         const Characteristics<int> &characteristics) : name(name), description(description), location(location),
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

float Destination::getMatching(Characteristics<int> &prio) {
    return prio.getMatching(characteristics);
}

Destination Destination::bestMatch(const std::vector<Destination> &v, Characteristics<int> prio, const Point &location) {
    float best = 0;
    Destination ret;
    bool ok = 0;
    for (auto it:v) {
        if(it.getLocation().Distance(location) > MAX_DISTANCE)
            continue;
        float curr = it.getMatching(prio);
        if (curr > best) {
            ok = 1;
            best = curr;
            ret = it;
        }
    }
    if(ok == 1)
        return ret;
    throw FrameErr("No destination found");
}

const std::string &Destination::getDescription() const {
    return description;
}

const Point &Destination::getLocation() const {
    return location;
}

void Destination::setMaxDistance(double maxDistance) {
    MAX_DISTANCE = maxDistance;
}

