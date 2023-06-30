//
// Created by raduc on 6/20/2023.
//

#include "Button_factory.h"

Button Button_factory::startButton() {
    Button_builder builder;
    return builder.position(100, 300)
            .size(100, 100)
            .text("Start")
            .textSize(30)
            .idleColor(sf::Color(0xACBEA3))
            .hoverColor(sf::Color::Red).build();
}

Button Button_factory::ratingButton(int rating) {
    Button_builder builder;
    return builder.position(30 + 60 * rating, 300)
            .size(40, 40)
            .idleColor(sf::Color::Black)
            .hoverColor(sf::Color(0xEB6534))
            .text(std::to_string(rating + 1))
            .textSize(20)
            .build();
}

Button Button_factory::yButton() {
    Button_builder builder;
    return builder.position(100, 300)
            .size(70, 70)
            .text("YES")
            .textSize(30)
            .idleColor(sf::Color::Black)
            .hoverColor(sf::Color(0xACBEA3)).build();
}

Button Button_factory::nButton() {
    Button_builder builder;
    return builder.position(300, 300)
            .size(70, 70)
            .idleColor(sf::Color::Black)
            .hoverColor(sf::Color::Red)
            .text("NO")
            .textSize(30).
            build();
}

Button Button_factory::submitButton() {

    Button_builder builder;
    return builder.position(100, 300)
            .size(100, 100)
            .text("Submit")
            .textSize(30)
            .idleColor(sf::Color::Black)
            .hoverColor(sf::Color(0xEB6534)).build();
}


