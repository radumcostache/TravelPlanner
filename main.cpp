#include <iostream>
#include <string>
#include <vector>
#include <cmath>
class Rating {
    float val;
    int numberOfRatings;
public:
    Rating() {val = 1; numberOfRatings = 0;}
    /*Rating(float val, int numberOfRatings) : val(val), numberOfRatings(numberOfRatings) {
        std::cerr << "Successful use of Rating constructor";
    }*/
    Rating(float val): val(val), numberOfRatings(1) {
        std::cerr << "Successful use of Rating constructor";
    };
    Rating(const Rating &other) : val(other.val), numberOfRatings(other.numberOfRatings) {
        std::cerr << "Successful use of Rating constructor";
    }
    ~Rating() {
        std::cerr << "Successful use of Rating destructor";
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
    /*int getNumberOfRatings() const {
        return numberOfRatings;
    }*/
    /*void setRating(int rating_) {
        val = rating_;
    }*/
    friend std::ostream &operator<<(std::ostream &os, const Rating &rating) {
        os << "val: " << rating.val << " numberOfRatings: " << rating.numberOfRatings;
        return os;
    }
};
class Point {
    float x, y;
public:
    Point() : x(0), y(0) {std::cerr << "Successful use of Point constructor";}
    Point(float x, float y) : x(x), y(y) {std::cerr << "Successful use of Point constructor";}
    Point(const Point & other) : x(other.x), y(other.y) {std::cerr << "Successful use of Point constructor";}
    ~Point() {
        std::cerr << "Successful use of Point destructor";
    }

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
    Attraction() : name(),  description(), location(), rating() {std::cerr << "Successful use of Attraction constructor";}
    Attraction(const std::string &name, const std::string &description, const Point &location, const Rating &rating)
            : name(name), description(description), location(location), rating(rating) {std::cerr << "Successful use of Attraction constructor";}
    Attraction(const Attraction & t) = default;
    ~Attraction() {
        std::cerr << "Successful use of Attraction destructor";
    }

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

    /*const Point & getLocation() {
        return location;
    }*/

    float Distance(Point & P) {
        return P.Distance(location);
    }

    friend std::ostream &operator<<(std::ostream &os, const Attraction &attraction) {
        os << "name: " << attraction.name << " description: " << attraction.description << " location: "
           << attraction.location << " reviews: " << attraction.rating;
        return os;
    }
};

class Characteristics {
public:
    Characteristics() = default;
    Characteristics(const Rating &museumRating_, const Rating &kidsRating_, const Rating &romanceRating_,
                    const Rating &foodRating_, const Rating &safetyRating_, const Rating &cleanRating_,
                    const Rating &nightLifeRating_, const std::string & architectureStyle_) : museumRating(museumRating_),
                    kidsRating(kidsRating_), romanceRating(romanceRating_), foodRating(foodRating_),
                    safetyRating(safetyRating_), cleanRating(cleanRating_), nightLifeRating(nightLifeRating_),
                    architectureStyle(architectureStyle_) {std::cerr << "Successful use of Characteristics constructor";}
    Characteristics(const float museumRating_, const float kidsRating_, const float romanceRating_,
                    const float foodRating_, const float safetyRating_, const float cleanRating_,
                    const float nightLifeRating_, const std::string & architectureStyle_) : museumRating(museumRating_),
                                                                                              kidsRating(kidsRating_), romanceRating(romanceRating_), foodRating(foodRating_),
                                                                                              safetyRating(safetyRating_), cleanRating(cleanRating_), nightLifeRating(nightLifeRating_),
                                                                                              architectureStyle(architectureStyle_) {std::cerr << "Successful use of Characteristics constructor";}
    Characteristics(const Characteristics &) = default;
    ~Characteristics() {
        std::cerr << "Successful use of Characteristics destructor";
    }
    float getMatching(Characteristics & c) {
        float ret = 0;
        if (c.architectureStyle == this->architectureStyle)
            ret += 5;
        ret += c.cleanRating.getVal() * this->cleanRating.getVal();
        ret += c.foodRating.getVal() * this->foodRating.getVal();
        ret += c.kidsRating.getVal() * this->foodRating.getVal();
        ret += c.nightLifeRating.getVal() * this->nightLifeRating.getVal();
        ret += c.museumRating.getVal() * this->museumRating.getVal();
        ret += c.safetyRating.getVal() * this->safetyRating.getVal();
        return ret;
    }
private:
    Rating museumRating, kidsRating, romanceRating, foodRating, safetyRating, cleanRating, nightLifeRating;
    std::string architectureStyle;

};

class Destination {
    std::string name;
    std::string description;
    Point location;
    std::vector<Attraction> attraction;
    Rating reviews, attractionRating;
    Characteristics characteristics;
public:
    Destination() = default;
    Destination(const std::string &name, const std::string &description, const Point &location,
                const std::vector<Attraction> &attraction, const Rating &rating,
                const Characteristics &characteristics) : name(name), description(description), location(location),
                                                          attraction(attraction), reviews(rating),
                                                          characteristics(characteristics) {
        Rating rt;
        for (auto it:attraction)
            rt.addRating(it.getRating().getVal());
        this->attractionRating = rt;
        std::cerr << "Successful use of Destination constructor";
    }
    Destination(const Destination &) = default;
    ~Destination() {
        std::cerr << "Successful use of Destination constructor";
    }

    Destination& operator=(const Destination & other) {
        name = other.name;
        description = other.name;
        location = other.location;
        attraction = other.attraction;
        reviews = other.reviews;
        attractionRating = other.attractionRating;
        return *this;
    }
    void addAttraction(Attraction A) {
        attraction.push_back(A);
        attractionRating.addRating(A.getRating());
    }
    float getMatching(Characteristics & prio) {
        return prio.getMatching(characteristics);
    }
    static Destination bestMatch(std::vector<Destination> &v, Characteristics & prio) {
        float best; 
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
    std::string & getName() {
        return this->name;
    }
    std::vector<Attraction> &topByDistance(Point P) {
        std::sort(attraction.begin(), attraction.end(), [&P](Attraction & A, Attraction & B) {return A.Distance(P) < B.Distance(P);});
        return attraction;
    }
    std::vector<Attraction> &topByCenter(){
        return topByDistance(location);
    }
    std::vector<Attraction> &topByReviews() {
        std::sort(attraction.begin(), attraction.end(), [](Attraction & A, Attraction & B) {return A.getRating().getVal() > B.getRating().getVal();});
        return attraction;
    }
    friend std::ostream &operator<<(std::ostream &os, const Destination &destination) {
        os << "name: " << destination.name << " description: " << destination.description << " location: "
           << destination.location << " attractions: ";

        for(auto it:destination.attraction) {
            os << it << ' ';
        }
        os << '\n';
        os << " reviews: " << destination.reviews
           << " attractionRating: " << destination.attractionRating;
        return os;
    };
};


int main() {
    Attraction PP("Palatul Parlamentului", "Palat in Bucuresti", Point(100, 100), Rating(4));
    Attraction MNA("Muzeul National de Arta", "Muzeu de Arta in Bucuresti", Point(80, 65), Rating(3));
    Attraction Beluga("Beluga", "Club de Noapte", Point(85, 80), Rating(3));
    std::vector<Attraction> atBuc;
    atBuc.push_back(PP);
    atBuc.push_back(MNA);
    atBuc.push_back(Beluga);

    Attraction NG("National Gallery", "Galerie de Arta", Point(1000, 900), Rating(5));
    Attraction Tate("Tate Musseum", "Muzeu de arta moderna", Point(1200, 30), Rating(4));
    std::vector <Attraction> atLon;
    atLon.push_back(NG);
    atLon.push_back(Beluga);
    Destination Buc("Bucuresti", "Capitala Romaniei", Point(90, 90), atBuc, Rating(4), Characteristics(2, 3, 4, 5, 4, 3, 3, "Baroque"));
    Destination Lon("Londra", "Capitala UK", Point(1000, 1000), atLon, Rating(5), Characteristics(4, 4, 4, 3, 3, 3, 4, "Clasic"));

    Lon.addAttraction(Attraction("LondonEye", "Roata", Point(1200, 1000), Rating(4)));
    int musInterest, kidInterest, ngtInterest, safInterest, clnInterest, romInterest, fodInterest;
    std::cout << "Pe o scara de la 1 la 5 cat de mult va intereseaza:\n";
    std::cout << "muzeele:";
    std::cin >> musInterest;
    std::cout << "activitatile pentru copii:";
    std::cin >> kidInterest;
    std::cout << "curatenia:";
    std::cin >> clnInterest;
    std::cout << "siguranta:";
    std::cin >> safInterest;
    std::cout << "viata de noapte:";
    std::cin >> ngtInterest;
    std::cout << "excursie romantica:";
    std::cin >> romInterest;
    std::cout << "mancarea:";
    std::cin >> fodInterest;
    std::string styArh;
    std::cout << "Ce stil arhitectural apreciati cel mai mult?";
    std::cout << styArh;
    Characteristics prio(musInterest, kidInterest, romInterest, fodInterest, safInterest, clnInterest, ngtInterest, styArh);
    std::vector<Destination> dst;
    dst.push_back(Lon);
    dst.push_back(Buc);
    Destination best = Destination::bestMatch(dst, prio);
    std::cout << "Cea mai buna destinatie pentru dvs este:" << best.getName();
    std::cout << "\nDaca doriti sa va aratam atractiile dupa rating apasati 1, sau dupa distanta din centru - 2";
    int choice;
    std::cin >> choice;
    std::vector <Attraction> bestAttr;
    if (choice == 1) {
        bestAttr = best.topByReviews();
    }
    else {
        bestAttr = best.topByCenter();
    }
    for (auto it:bestAttr)
        std::cout << it;
    return 0;
}
