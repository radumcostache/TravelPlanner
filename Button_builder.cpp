//
// Created by raduc on 6/20/2023.
//

#include "Button_builder.h"

Button_builder &Button_builder::position(double x, double y) {
    button.setPosition(sf::Vector2f(x, y));
    return *this;
}

Button_builder &Button_builder::size(double x, double y) {
    button.m_shape.setSize(sf::Vector2f(x, y));
    return *this;
}

Button_builder &Button_builder::text(std::string text) {
    button.m_text.setString(text);
    return *this;
}

Button_builder &Button_builder::textSize(int textSize) {
    button.m_text.setCharacterSize(textSize);
    return *this;
}

Button_builder &Button_builder::idleColor(sf::Color idleColor) {
    button.m_idleColor = idleColor;
    return *this;
}

Button_builder &Button_builder::hoverColor(sf::Color hoverColor) {
    button.m_hoverColor = hoverColor;
    return *this;
}

Button Button_builder::build() {
    button.m_shape.setFillColor(button.m_idleColor);
    button.m_text.setFillColor(sf::Color::White);
    sf::Font font;
    font.loadFromFile("fonts/arial.ttf");
    button.m_text.setFont(font);

    button.m_text.setPosition(button.m_shape.getPosition().x + button.m_shape.getSize().x / 2.f - button.m_text.getLocalBounds().width / 2.f, button.m_shape.getPosition().y + button.m_shape.getSize().y / 2.f - button.m_text.getLocalBounds().height / 2.f);
    return button;
}
