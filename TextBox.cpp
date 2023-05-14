//
// Created by raduc on 22.04.2023.
//

#include "TextBox.h"


TextBox::TextBox(sf::Vector2f position, sf::Vector2f size, unsigned int textSize, sf::Color textColor, sf::Color backgroundColor)
{
    m_shape.setPosition(position);
    m_shape.setSize(size);
    m_shape.setFillColor(backgroundColor);

    m_font.loadFromFile("fonts/arial.ttf");
    m_text.setFont(m_font);
    m_text.setCharacterSize(textSize);
    m_text.setFillColor(textColor);
    m_text.setPosition(position.x + 5.f, position.y + 5.f);

    m_string = "";
    m_selected = false;
}

void TextBox::draw(sf::RenderWindow& window)
{
    window.draw(m_shape);
    window.draw(m_text);
}

void TextBox::handleEvent(sf::Event event)
{
    if (event.type == sf::Event::TextEntered)
    {
        if (m_selected)
        {
            if (event.text.unicode == 8 && !m_string.empty()) // Backspace
            {
                m_string.pop_back();
            }
            else if (event.text.unicode == 13) // Enter
            {
                // Do something when Enter is pressed
            }
            else if (event.text.unicode < 128 && event.text.unicode != 8) // Printable character
            {
                m_string += static_cast<char>(event.text.unicode);
            }

            m_text.setString(m_string);
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

        if (m_shape.getGlobalBounds().contains(mousePos))
        {
            m_selected = true;
        }
        else
        {
            m_selected = false;
        }
    }
}

std::string TextBox::getText() const
{
    return m_string;
}

void TextBox::reset() {
    m_string = "";
    m_text.setString(m_string);
}
