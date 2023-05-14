//
// Created by raduc on 22.04.2023.
//

#ifndef OOP_STARTFRAME_H
#define OOP_STARTFRAME_H

#include "Frame.h"
#include "TextBox.h"

#include "FrameErr.h"
class startFrame: public Frame{
private:


    sf::Font font;
    sf::Text latiText;
    sf::Text longiText;

    TextBox latiBox{sf::Vector2f(300, 100), sf::Vector2f(200, 50), 30, sf::Color::Black, sf::Color::Green};
    TextBox longiBox{sf::Vector2f(300, 200), sf::Vector2f(200, 50), 30, sf::Color::Black, sf::Color::Green};

public:
    startFrame();
    std::string handleEvent(sf::Event event, sf::RenderWindow &window) override;
    void draw(sf::RenderWindow &window) override;
    void reset() override;
    explicit startFrame(User &user);
};


#endif //OOP_STARTFRAME_H
