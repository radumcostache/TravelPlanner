//
// Created by raduc on 07.05.2023.
//

#include <iostream>
#include "Question.h"

Question::~Question() {}

Question::Question(const std::string & question, Characteristics &characteristics) : question(question), characteristics(characteristics) {std::cout << "Question constructor" << std::endl;}

const Characteristics &Question::getCharacteristics() const {
    return characteristics;
}


