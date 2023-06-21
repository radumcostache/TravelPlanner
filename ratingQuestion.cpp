//
// Created by raduc on 07.05.2023.
//

#include "ratingQuestion.h"
#include "Button_factory.h"

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

ratingQuestion::ratingQuestion(const std::string & question, Characteristics<int> &characteristics) : Question(question, characteristics) {
    Button_builder b;
    buttons[0] = Button_factory::ratingButton(0);
    buttons[1] = Button_factory::ratingButton(1);
    buttons[2] = Button_factory::ratingButton(2);
    buttons[3] = Button_factory::ratingButton(3);
    buttons[4] = Button_factory::ratingButton(4);
}

/*void ratingQuestion::updateUser(User &user) {
    user.updateCharacteristics(chr, answer);
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
