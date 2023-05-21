//
// Created by raduc on 07.05.2023.
//

#include "QFrame.h"
#include "ratingQuestion.h"
#include "tfQuestion.h"
#include "FrameErr.h"
#include "boxQuestion.h"

void QFrame::draw(sf::RenderWindow &window) {
    questions[currentQuestion]->showQuestion(window);
}

void QFrame::nextQuestion() {
    currentQuestion++;
}

std::string QFrame::handleEvent(sf::Event event, sf::RenderWindow &window) {
        std::string result = questions[currentQuestion]->handleEvent(event, window);
        if (!result.empty()) {
            if (result == "YES") {
                auto & ch = questions[currentQuestion]->getCharacteristics();
                auto *q = dynamic_cast<boxQuestion*>(questions[currentQuestion].get());
                if (q) {
                    q->passAnswer(user);
                }
                else {
                    auto mult = questions[currentQuestion]->getAnswer();
                    user.updateCharacteristics(ch, mult);
                }

            }
            nextQuestion();
            if (currentQuestion == questions.size()) {
                return "end";
            }
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

        if (qtype == "box") {
            std::shared_ptr<Question> q = std::make_shared<boxQuestion>(question);
            questions.push_back(q);
        }else {
            double d[4];
            for (double & i : d) {
                f >> i;
            }
            ch = Characteristics(d[0], d[1], d[2], d[3]);
            if (qtype == "yn") {
                std::shared_ptr<Question> q = std::make_shared<tfQuestion>(question, ch);
                questions.push_back(q);
            } else if (qtype == "rating") {
                std::shared_ptr<Question> q = std::make_shared<ratingQuestion>(question, ch);
                questions.push_back(q);
            }
            else {
                throw FrameErr("Invalid question type");
            }
        }
    }
}

void QFrame::reset() {
    currentQuestion = 0;
}
