//
// Created by raduc on 22.04.2023.
//

#include "startFrame.h"
#include "Button_factory.h"

std::string startFrame::handleEvent(sf::Event event, sf::RenderWindow &window) {
    for (auto button : buttons) {
        std::string s = button.handleEvent(event, window);
        if (s == "Start") {
            double lati = std::stod(latiBox.getText());
            double longi = std::stod(longiBox.getText());
            if (lati < -90 || lati > 90 || longi < -180 || longi > 180) {
                std::string er = "Invalid coordinates";
                throw bad_input(er);
            }
            user.updateLocation(lati, longi);
            return "Start";
        }
        else if (s == "Exit") {
            exit(0);
        }
    }
    latiBox.handleEvent(event);
    longiBox.handleEvent(event);

    return "";
}

void startFrame::draw(sf::RenderWindow &window) {
    drawBackground(window);
    for (auto button : buttons) {
        button.draw(window);
    }
    window.draw(latiText);
    window.draw(longiText);

    latiBox.draw(window);
    longiBox.draw(window);

    if (err != "") {
        sf::Text errText;
        errText.setFont(font);
        errText.setString(err);
        errText.setCharacterSize(30);
        errText.setPosition(100, 400);
        errText.setFillColor(sf::Color::Red);
        window.draw(errText);
    }
}

startFrame::startFrame(User &user) : Frame(user) {
    font.loadFromFile("fonts/arial.ttf");
    latiText.setFont(font);
    latiText.setString("Latitude");
    latiText.setCharacterSize(30);
    latiText.setPosition(100, 100);
    latiText.setFillColor(sf::Color::White);

    longiText.setFont(font);
    longiText.setString("Longitude");
    longiText.setCharacterSize(30);
    longiText.setPosition(100, 200);
    longiText.setFillColor(sf::Color::White);

    //Button startButton(sf::Vector2f(100, 300), sf::Vector2f(100, 100), "Start", 30, sf::Color::Green, sf::Color::Red);
    addButton(Button_factory::startButton());
}

void startFrame::reset() {
    latiBox.reset();
    longiBox.reset();
}

