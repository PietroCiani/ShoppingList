//
// Created by delta on 10/08/24.
//


#include <iostream>
#include <utility>
#include "Button.h"

Button::Button(const std::string &text, sf::Vector2f pos, std::function<void()> callback, const sf::Font& font, sf::Vector2f size) : onClickCallback(std::move(callback)), font(font){
    sf::Color bgLighter(80,73,69);
    sf::Color fg(251,241,199);

    buttonText.setFont(font);
    buttonText.setCharacterSize(14);
    buttonText.setFillColor(fg);
    buttonText.setString(text);

    buttonShape.setPosition(pos);
    buttonShape.setSize(size);
    buttonShape.setFillColor(bgLighter);
    sf::FloatRect textRect = buttonText.getLocalBounds();
    buttonText.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);
    buttonText.setPosition(
            buttonShape.getPosition().x + buttonShape.getSize().x / 2.f,
            buttonShape.getPosition().y + buttonShape.getSize().y / 2.f
    );
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
    if (buttonShape.getGlobalBounds().contains(mousePos)) onClickCallback();
}

void Button::setCallback(std::function<void()> callback) {
    onClickCallback = std::move(callback);
}

void Button::clicked() {
    onClickCallback();
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(buttonShape, states);
    target.draw(buttonText, states);
}

