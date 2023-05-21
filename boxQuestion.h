//
// Created by raduc on 5/21/2023.
//

#ifndef OOP_BOXQUESTION_H
#define OOP_BOXQUESTION_H


#include "Button.h"
#include "TextBox.h"
#include "Question.h"
#include "User.h"

class boxQuestion : public Question{
private:
    Button submitButton;
    TextBox textBox;

public:
    std::string handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void showQuestion(sf::RenderWindow &window) override;
    void passAnswer(User &usr);
    explicit boxQuestion(const std::string & question);
};


#endif //OOP_BOXQUESTION_H
