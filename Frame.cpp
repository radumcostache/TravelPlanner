//
// Created by raduc on 19.04.2023.
//

#include "Frame.h"


void Frame::addButton(Button button) {
    buttons.push_back(button);
}

void Frame::drawBackground(sf::RenderWindow &window) {
    window.draw(background);
}

Frame::Frame(User &user) : user(user) {
    font.loadFromFile("fonts/arial.ttf");
    background.setSize(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color::White);
}

void Frame::addError(std::string & error) {
    err = error;

}

