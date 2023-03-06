#include <iostream>
#include <string>
#include <vector>
#include <cmath>
class Rating {
    float val;
    int numberOfRatings;
public:
    Rating() {val = 0; numberOfRatings = 0;}
    Rating(float val, int numberOfRatings) : val(val), numberOfRatings(numberOfRatings) {}
    Rating(const Rating &other) : val(other.val), numberOfRatings(other.numberOfRatings) {}
    Rating(Rating && other) : val{std::move(other.val)}, numberOfRatings{std::move(other.numberOfRatings)} {}
    ~Rating() {

    }

    Rating& operator=(const Rating& other) {
        val = other.val;
        numberOfRatings = other.numberOfRatings;
        return *this;
    }
    void addRating(int newRating) {
        val *= (float)numberOfRatings;
        val += (float)newRating;
        numberOfRatings++;
        val /= (float)numberOfRatings;
    }
    void addRating(const Rating &newRating) {
        val *= (float)numberOfRatings;
        val += newRating.getVal();
        numberOfRatings++;
        val /= (float)numberOfRatings;
    }
    float getVal() const {
        return val;
    }
    int getNumberOfRatings() const {
        return numberOfRatings;
    }

    friend std::ostream &operator<<(std::ostream &os, const Rating &rating) {
        os << "val: " << rating.val << " numberOfRatings: " << rating.numberOfRatings;
        return os;
    }
};
class Point {
    float x, y;
public:
    Point() : x(0), y(0) {}
    Point(float x, float y) : x(x), y(y) {}
    Point(const Point & other) : x(other.x), y(other.y) {}
    Point(Point && other) : x{std::move(other.x)}, y(std::move(other.y)) {}
    ~Point() {}

    Point& operator=(const Point &other) {
        x = other.x;
        y = other.y;
        return *this;
    }

    float Distance(const Point &P) const {
        return sqrt((P.x - P.y) * (P.x - P.y));
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }


};
class Attraction {
    std::string name;
    std::string description;
    Point location;
    Rating rating;
public:
    Attraction() : name(),  description(), location(), rating() {}
    Attraction(const std::string &name, const std::string &description, const Point &location, const Rating &rating)
            : name(name), description(description), location(location), rating(rating) {}
    Attraction(const Attraction & t) : name(t.name), rating(t.rating), location(t.location), description(t.description) {}
    Attraction(Attraction && other) : name{std::move(other.name)}, rating{std::move(other.rating)},
                                      location{std::move(other.location)}, description{std::move(other.description)} {}
    ~Attraction() {}

    Attraction &operator =(const Attraction &other) {
        name = other.name;
        description = other.description;
        location = other.location;
        rating = other.rating;
        return *this;
    }

    const Rating &getRating() const {
        return rating;
    }

    const Point & getLocation() {
        return location;
    }

    float Distance(Point & P) {
        return P.Distance(location);
    }

    friend std::ostream &operator<<(std::ostream &os, const Attraction &attraction) {
        os << "name: " << attraction.name << " description: " << attraction.description << " location: "
           << attraction.location << " rating: " << attraction.rating;
        return os;
    }
};

class Destination {
    std::string name;
    std::string description;
    Point location;
    std::vector<Attraction> attraction;
    Rating rating, attractionRating;
public:
    Destination(const std::string &name_, const std::string &description_, const Point &location_,
                const std::vector<Attraction> & attraction_, const Rating &rating_, const Rating &attractionRating_) : name(name_), description(description_),
                                                                                                                     location(location_), attraction(attraction_),
                                                                                                                     rating(rating_), attractionRating(attractionRating_) {}
    Destination(const Destination & other) : name(other.name), description(other.description),
                                             location(other.location), attraction(other.attraction),
                                             rating(other.rating), attractionRating(other.rating) {}
    Destination(Destination && other) : rating{std::move(other.rating)}, name{std::move(other.name)},
                                        location{std::move(other.location)},
                                        attraction(std::move(other.attraction)), description{std::move(other.description)},
                                        attractionRating{std::move(other.attractionRating)} {}
    ~Destination() {}

    Destination& operator=(const Destination & other) {
        name = other.name;
        description = other.name;
        location = other.location;
        attraction.clear();
        for (auto it:other.attraction)
            attraction.push_back(it);
        rating = other.rating;
        attractionRating = other.attractionRating;
        return *this;
    }


    void addAttraction(Attraction &A) {
        attraction.push_back(A);
        attractionRating.addRating(A.getRating());
    }
    float distanceFromCenter(Attraction &A) {
        return A.Distance(location);
    }
    std::vector<Attraction> &topByDistance(Point P) {
        sort(attraction.begin(), attraction.end(), [&P](Attraction & A, Attraction & B) {return A.Distance(P) < B.Distance(P);});
        return attraction;
    }
    std::vector<Attraction> &topByCenter(){
        return topByDistance(location);
    }

    friend std::ostream &operator<<(std::ostream &os, const Destination &destination) {
        os << "name: " << destination.name << " description: " << destination.description << " location: "
           << destination.location << " attractions: ";

        for(auto it:destination.attraction) {
            os << it << ' ';
        }
        os << '\n';
        os << " rating: " << destination.rating
           << " attractionRating: " << destination.attractionRating;
        return os;
    };
};


int main() {

    return 0;
}
