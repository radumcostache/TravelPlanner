//
// Created by raduc on 19.04.2023.
//

#ifndef OOP_FRAME_H
#define OOP_FRAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.h"
#include "User.h"
#include <string>
#include <memory>

class Frame {
private:
    sf::RectangleShape background;
    sf::Font font;
protected:
    std::vector <Button> buttons;
    User &user;
    std::string err;
public:
    explicit Frame(User &user);
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual std::string handleEvent(sf::Event event, sf::RenderWindow& window) = 0;
    virtual void reset() = 0;
    void addError(std::string & error);
    void drawBackground(sf::RenderWindow& window);
    void addButton(Button button);
    virtual ~Frame() {std::cout << "Frame destructor called\n";};

};


#endif //OOP_FRAME_H
