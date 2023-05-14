//
// Created by raduc on 22.04.2023.
//

#ifndef OOP_TEXTBOX_H
#define OOP_TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>

class TextBox
{
public:
    TextBox(sf::Vector2f position, sf::Vector2f size, unsigned int textSize, sf::Color textColor, sf::Color backgroundColor);
    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event event);
    std::string getText() const;
    void reset();

private:
    sf::Font m_font;
    sf::RectangleShape m_shape;
    sf::Text m_text;
    std::string m_string;
    bool m_selected;
};


#endif //OOP_TEXTBOX_H
