//
// Created by raduc on 07.05.2023.
//

#include <iostream>
#include "tfQuestion.h"

tfQuestion::tfQuestion(const std::string & question, Characteristics &characteristics) : Question(question, characteristics),
    yesButton(sf::Vector2f(50, 50), sf::Vector2f(40, 40),"YES",20, sf::Color::Black, sf::Color::Green),
    noButton(sf::Vector2f(90, 50), sf::Vector2f(40, 40),"NO",20, sf::Color::Black, sf::Color::Red) {
    std::cout << "tfQuestion constructor" << std::endl;
}

tfQuestion::~tfQuestion() {
    std::cout << "tfQuestion destructor" << std::endl;
}

void tfQuestion::showQuestion(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("fonts/arial.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(question);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(10, 10);
    window.draw(text);
    yesButton.draw(window);
    noButton.draw(window);
}

std::string tfQuestion::handleEvent(sf::Event event, sf::RenderWindow &window) {
    std::string s = yesButton.handleEvent(event, window);
    if (!s.empty()) {
        return s;
    }
    s = noButton.handleEvent(event, window);
    return s;
}
