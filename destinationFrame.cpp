//
// Created by raduc on 5/15/2023.
//

#include "destinationFrame.h"

destinationFrame::destinationFrame(User &user, Destination &destination) : Frame(user)  {
    font.loadFromFile("fonts/arial.ttf");
    nameText.setFont(font);
    nameText.setCharacterSize(20);
    nameText.setFillColor(sf::Color::Red);
    nameText.setPosition(20, 100);
    nameText.setString("You are going to " + destination.getName() + " " +
                        std::to_string(user.getLocation().Distance(destination.getLocation())) + "km away");

    descriptionText.setFont(font);
    descriptionText.setCharacterSize(10);
    descriptionText.setFillColor(sf::Color::Black);
    descriptionText.setPosition(20, 150);
    descriptionText.setString(destination.getDescription());

    attractionText.setFont(font);
    attractionText.setCharacterSize(30);
    attractionText.setFillColor(sf::Color::Black);
    attractionText.setPosition(100, 300);
    std::string attractions;
    auto att = destination.topByReviews();
    for (auto it:att) {
        attractions += it.getName() + " " + std::to_string((int)it.getRating().getVal()) + "*\n";
        std::cout << "Attraction Tier: " << it.getChr() << '\n';
    }
    sf::String sfTmp = sf::String::fromUtf8(attractions.begin(), attractions.end());
    attractionText.setString(sfTmp);
}

std::string destinationFrame::handleEvent(sf::Event event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            return "YES";
        }
    }

    return window.isOpen() ? "" : "YES";
}

void destinationFrame::reset() {
    std::cout << "reset" << std::endl;
}

void destinationFrame::draw(sf::RenderWindow &window) {
    drawBackground(window);
    window.draw(nameText);
    window.draw(descriptionText);
    window.draw(attractionText);
}
