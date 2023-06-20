//
// Created by raduc on 19.04.2023.
//

#include "Button.h"
    Button::Button() {
        m_font.loadFromFile("fonts/arial.ttf");
        m_text.setFont(m_font);
    }
    Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text, int textSize, sf::Color idleColor, sf::Color hoverColor) : m_idleColor(idleColor), m_hoverColor(hoverColor) {
        m_shape.setPosition(position);
        m_shape.setSize(size);
        m_shape.setFillColor(idleColor);

        m_font.loadFromFile("fonts/arial.ttf");
        m_text.setFont(m_font);
        m_text.setString(text);
        m_text.setCharacterSize(textSize);
        m_text.setPosition(position.x + size.x / 2.f - m_text.getLocalBounds().width / 2.f, position.y + size.y / 2.f - m_text.getLocalBounds().height / 2.f);
        m_text.setFillColor(sf::Color::White);

    }
    std::string Button::handleEvent(sf::Event event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (m_shape.getGlobalBounds().contains(mousePos)) {
                m_shape.setFillColor(m_hoverColor);
            }
            else {
                m_shape.setFillColor(m_idleColor);
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (m_shape.getGlobalBounds().contains(mousePos))
                    return m_text.getString();
            }
        }
        return "";
    }

    void Button::draw(sf::RenderWindow& window) {
        window.draw(m_shape);
        m_text.setFont(m_font);
        window.draw(m_text);
    }

    void Button::setPosition(sf::Vector2f position) {
        m_shape.setPosition(position);
        m_text.setPosition(position.x + m_shape.getSize().x / 2.f - m_text.getLocalBounds().width / 2.f, position.y + m_shape.getSize().y / 2.f - m_text.getLocalBounds().height / 2.f);
    }

