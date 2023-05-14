//
// Created by raduc on 07.05.2023.
//

#ifndef OOP_TFQUESTION_H
#define OOP_TFQUESTION_H


#include "Question.h"
#include "Button.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class tfQuestion : public Question{
public:
    Button yesButton;
    Button noButton;
    tfQuestion(std::string question, Characteristics &characteristics);
    ~tfQuestion() override;

    void showQuestion(sf::RenderWindow &window) override;
    std::string handleEvent(sf::Event event, sf::RenderWindow &window) override;
};


#endif //OOP_TFQUESTION_H
