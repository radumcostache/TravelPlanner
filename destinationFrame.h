//
// Created by raduc on 5/15/2023.
//

#ifndef OOP_DESTINATIONFRAME_H
#define OOP_DESTINATIONFRAME_H


#include "Frame.h"
#include "Destination.h"

class destinationFrame : public Frame {
    Destination  &destination;
    sf::Font font;
    sf::Text nameText;
    sf::Text descriptionText;

    sf::Text attractionText;

public:
    destinationFrame(User &user, Destination & destination);
    std::string handleEvent(sf::Event event, sf::RenderWindow &window) override;
    void draw(sf::RenderWindow &window) override;
    void reset() override;
};


#endif //OOP_DESTINATIONFRAME_H
