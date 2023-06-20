//
// Created by raduc on 19.04.2023.
//

#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H


//
// Created by raduc on 19.04.2023.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.h"
#include <iostream>
#include <string>


class Button {
public:
    Button();
    Button(sf::Vector2f position, sf::Vector2f size, std::string text, int textSize, sf::Color idleColor, sf::Color hoverColor);
    ~Button() = default;
    std::string handleEvent(sf::Event event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void setPosition(sf::Vector2f position);
    friend class Button_builder;

private:
    sf::RectangleShape m_shape;
    sf::Text m_text;
    sf::Color m_idleColor;
    sf::Color m_hoverColor;
    sf::Font m_font;
};




#endif //OOP_BUTTON_H
