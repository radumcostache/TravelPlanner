//
// Created by raduc on 5/21/2023.
//

#include "boxQuestion.h"
#include "Button_factory.h"

boxQuestion::boxQuestion(const std::string &question) : Question(question),
                                                        textBox (sf::Vector2f(100, 200),
                                                                 sf::Vector2f(200, 50), 20,
                                                                 sf::Color::Black, sf::Color::White)

{
    submitButton = Button_factory::submitButton();
    std::cout << "boxQuestion constructor" << std::endl;
}

void boxQuestion::showQuestion(sf::RenderWindow &window) {
    submitButton.draw(window);
    textBox.draw(window);

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

}

std::string boxQuestion::handleEvent(sf::Event event, sf::RenderWindow &window) {
    textBox.handleEvent(event);
    std::string s = submitButton.handleEvent(event, window);
    if (!s.empty()) {
        s = textBox.getText();
        answer = stod(s);
        return "YES";
    }
    return s;
}

void boxQuestion::passAnswer(User &usr) {
    usr.addAnswer(answer);

}
