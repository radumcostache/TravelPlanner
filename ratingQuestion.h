//
// Created by raduc on 07.05.2023.
//

#ifndef OOP_RATINGQUESTION_H
#define OOP_RATINGQUESTION_H


#include "Question.h"
#include "Button.h"
#include "User.h"

class ratingQuestion : public Question{
private:
    Button buttons[5];
    //void updateUser(User &user);
    std::string handleEvent(sf::Event event, sf::RenderWindow& window) override;
public:
    ratingQuestion(const std::string & question, Characteristics &characteristics);
    void showQuestion(sf::RenderWindow &window) override;

};


#endif //OOP_RATINGQUESTION_H
