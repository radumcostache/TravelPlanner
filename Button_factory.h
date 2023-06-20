//
// Created by raduc on 6/20/2023.
//

#ifndef OOP_BUTTON_FACTORY_H
#define OOP_BUTTON_FACTORY_H

#include "Button_builder.h"


class Button_factory {
public:
    static Button startButton();
    static Button ratingButton(int rating);
    static Button yButton();
    static Button nButton();
    static Button submitButton();

};


#endif //OOP_BUTTON_FACTORY_H
