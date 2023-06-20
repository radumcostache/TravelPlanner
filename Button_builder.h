//
// Created by raduc on 6/20/2023.
//

#ifndef OOP_BUTTON_BUILDER_H
#define OOP_BUTTON_BUILDER_H

#include "Button.h"


class Button_builder {
    Button button;
public:
    Button_builder() = default;
    Button_builder& position(double x, double y);
    Button_builder& size(double x, double y);
    Button_builder& text(std::string text);
    Button_builder& textSize(int textSize);
    Button_builder& idleColor(sf::Color idleColor);
    Button_builder& hoverColor(sf::Color hoverColor);
    Button build();
};


#endif //OOP_BUTTON_BUILDER_H
