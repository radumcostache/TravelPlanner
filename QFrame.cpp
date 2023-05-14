//
// Created by raduc on 07.05.2023.
//

#include "QFrame.h"
#include "ratingQuestion.h"
#include "tfQuestion.h"
#include "FrameErr.h"

void QFrame::draw(sf::RenderWindow &window) {
    if (currentQuestion < questions.size())
        questions[currentQuestion]->showQuestion(window);
    else
        throw end_frame("No more questions");
}

void QFrame::nextQuestion() {
    currentQuestion++;
    if (currentQuestion >= questions.size()) {
        std::string er = "No more questions";
        throw end_frame(er);
    }
}

std::string QFrame::handleEvent(sf::Event event, sf::RenderWindow &window) {
        std::string result = questions[currentQuestion]->handleEvent(event, window);
        if (!result.empty()) {
            if (result == "YES") {
                auto ch = questions[currentQuestion]->getCharacteristics();
                    if(auto *q = dynamic_cast<ratingQuestion *>(questions[currentQuestion].get()))
                        user.updateCharacteristics(ch, q->getAnswer());
                    else
                        if (auto *q = dynamic_cast<tfQuestion *>(questions[currentQuestion].get()))
                        user.updateCharacteristics(ch, 3);
                    else
                        std::cout << "Error casting" << std::endl;
            }
            nextQuestion();
            return "next";
        }
        return result;
}

QFrame::QFrame(User &user, std::ifstream &f) : Frame(user) {
    std::string qtype, question;
    Characteristics ch;
    while (f >> qtype) {
        f.get();
        std::getline(f, question);
        double d[4];
        for (int i = 0; i < 4; ++i) {
            f >> d[i];
        }
        ch = Characteristics(d[0], d[1], d[2], d[3]);
        if (qtype == "yn") {
            std::shared_ptr<Question> q = std::make_shared<tfQuestion>(question, ch);
            questions.push_back(q);
        } else if (qtype == "rating") {
            std::shared_ptr<Question> q = std::make_shared<ratingQuestion>(question, ch);
            questions.push_back(q);
        } else {
            std::cout << "Invalid question type" << std::endl;
        }
    }
}

void QFrame::reset() {
    currentQuestion = 0;
}
