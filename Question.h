//
// Created by raduc on 07.05.2023.
//

#ifndef OOP_QUESTION_H
#define OOP_QUESTION_H

#include "Characteristics.h"
#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"


class Question {
protected:
    std::string question;
    Characteristics characteristics;
public:
    Question(const std::string & question, Characteristics & characteristics);
    Question() = default;
    virtual ~Question();
    virtual void showQuestion(sf::RenderWindow &window) = 0;
    virtual std::string handleEvent(sf::Event event, sf::RenderWindow& window) = 0;
    const Characteristics &getCharacteristics() const;

};


#endif //OOP_QUESTION_H
