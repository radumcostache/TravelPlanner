#include <fstream>
#include <string>
#include <vector>
#include "Rating.h"
#include "Point.h"
#include "Destination.h"
#include "Characteristics.h"
#include "Attraction.h"
#include "startFrame.h"
#include "QFrame.h"
#include "destinationFrame.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

double Destination::MAX_DISTANCE = 1000.5;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Text text;
    sf::Font font;
    font.loadFromFile("fonts/arial.ttf");
    text.setFont(font);
    text.setString("Hello world");

    text.setCharacterSize(24);

    text.setFillColor(sf::Color::Red);

    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    User & user = User::getUser();
    Frame * F = new startFrame(user);

    std::vector<Destination> destinations;
    std::ifstream dest("destinations.txt");
    std::string destName;
    while (dest >> destName) {
        std::string destDesc;
        dest.get();
        std::getline(dest, destDesc);
        double lati, longi;
        dest >> lati >> longi;
        int nAttr;
        dest >> nAttr;
        std::vector<Attraction> attractions;
        for (int i = 0; i < nAttr; i++) {
            std::string attrName;
            dest.get();
            std::getline(dest, attrName);
            double rating;
            dest >> rating;
            Attraction a(attrName, Rating(rating));
            attractions.push_back(a);
        }
        double d[4];
        for (int i = 0; i < 4; ++i) {
            dest >> d[i];
        }
        Characteristics characteristics(d[0], d[1], d[2], d[3]);
        Destination dst(destName, destDesc, Point(lati, longi), attractions, characteristics);
        destinations.push_back(dst);
    }
    while (window.isOpen()) {
        sf::Event event;
        window.clear(sf::Color::Blue);
        F->draw(window);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            try{
                std::string s = F->handleEvent(event, window);
                if (s == "Start") {
                    delete F;
                    std::ifstream f("questions.txt");
                    F = new QFrame(user, f);
                }
                else if(s == "end") {
                    auto chr = user.getCharacteristics();
                    Destination::setMaxDistance(user.getAnswers()[0]);
                    Destination d = Destination::bestMatch(destinations, chr, user.getLocation());
                    delete F;
                    F = new destinationFrame(user, d);

                }
            }catch (bad_input & e){
                F->reset();
                F->addError(e.what());
            }catch (FrameErr & e) {
                delete F;
                F = new startFrame(user);
                F->addError(e.what());
            }

        }
        window.display();
    }
    delete F;
    return 0;
}
