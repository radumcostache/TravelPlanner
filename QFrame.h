//
// Created by raduc on 07.05.2023.
//

#ifndef OOP_QFRAME_H
#define OOP_QFRAME_H


#include "Frame.h"
#include "fstream"
#include "Question.h"

class QFrame : public Frame{
private:
    std::vector <std::shared_ptr<Question>> questions;
    int currentQuestion = 0;
    void nextQuestion();
public:
    QFrame(User & user, std::ifstream & f);
    void draw(sf::RenderWindow &window) override;
    void reset() override;
    std::string handleEvent(sf::Event event, sf::RenderWindow &window) override;
};


#endif //OOP_QFRAME_H
