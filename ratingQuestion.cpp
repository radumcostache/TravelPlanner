//
// Created by raduc on 07.05.2023.
//

#include "ratingQuestion.h"

void ratingQuestion::showQuestion(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("fonts/arial.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(question);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(10, 10);
    window.draw(text);
    for (auto & button : buttons) {
        button.draw(window);
    }


}

ratingQuestion::ratingQuestion(std::string question, Characteristics &characteristics) : Question(question, characteristics) {
    buttons[0] = Button(sf::Vector2f(30, 100), sf::Vector2f(40, 40),"1",
                        20, sf::Color::Black, sf::Color::Cyan);
    buttons[1] = Button(sf::Vector2f(90, 100), sf::Vector2f(40, 40),"2",
                        20, sf::Color::Black, sf::Color::Cyan);
    buttons[2] = Button(sf::Vector2f(150, 100), sf::Vector2f(40, 40),"3",
                        20, sf::Color::Black, sf::Color::Cyan);
    buttons[3] = Button(sf::Vector2f(210, 100), sf::Vector2f(40, 40),"4",
                        20, sf::Color::Black, sf::Color::Cyan);
    buttons[4] = Button(sf::Vector2f(270, 100), sf::Vector2f(40, 40),"5",
                        20, sf::Color::Black, sf::Color::Cyan);
}

/*void ratingQuestion::updateUser(User &user) {
    user.updateCharacteristics(characteristics, answer);
}*/

std::string ratingQuestion::handleEvent(sf::Event event, sf::RenderWindow &window) {
    for (int i = 0; i < 5; i++) {
        std::string s = buttons[i].handleEvent(event, window);
        if (!s.empty()) {
            answer = i + 1;
            return "YES";
        }
    }
    return "";
}

int ratingQuestion::getAnswer() const {
    return answer;
}
