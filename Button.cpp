//
// Created by delta on 10/08/24.
//


#include <iostream>
#include "Button.h"

Button::Button(const std::string &text, sf::Vector2f pos, sf::Vector2f size) {
    sf::Color bg(80,73,69);
    sf::Color fg(251,241,199);

    buttonShape.setSize(size);
    buttonShape.setPosition(pos);
    buttonShape.setFillColor(bg);
    buttonShape.setOutlineColor(fg);
    buttonShape.setOutlineThickness(2);

    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(14);
    buttonText.setFillColor(fg);

    sf::FloatRect textRect = buttonText.getLocalBounds();
    buttonText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    buttonText.setPosition(buttonShape.getPosition().x + (buttonShape.getSize().x / 2.0f), buttonShape.getPosition().y + (buttonShape.getSize().y / 2.0f));
}

void Button::setPosition(sf::Vector2f newPos) {
    buttonShape.setPosition(newPos);
    buttonText.setPosition(newPos.x + buttonShape.getSize().x / 2.0f, newPos.y + buttonShape.getSize().y / 2.0f);
}

void Button::setSize(sf::Vector2f newSize) {
    buttonShape.setSize(newSize);
    buttonText.setPosition(buttonShape.getPosition().x + buttonShape.getSize().x / 2.0f, buttonShape.getPosition().y + buttonShape.getSize().y / 2.0f);

}

void Button::checkClicked(const sf::Vector2f &mousePos) {
//    if (mousePos.x >= buttonShape.getPosition().x && mousePos.x <= buttonShape.getPosition().x + buttonShape.getSize().x &&
//        mousePos.y >= buttonShape.getPosition().y && mousePos.y <= buttonShape.getPosition().y + buttonShape.getSize().y)
//        enable();
if (buttonShape.getGlobalBounds().contains(mousePos)) enable();
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(buttonShape);
    window.draw(buttonText);
}

void Button::enable() {
    std::cout << "Button '" << std::string(buttonText.getString()) << "' clicked" << std::endl;
    //TODO: handle button click
}
