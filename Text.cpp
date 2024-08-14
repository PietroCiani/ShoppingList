//
// Created by delta on 14/08/24.
//

#include "Text.h"

#include <utility>
#include <iostream>

Text::Text(std::string string, const sf::Vector2f &pos, const int size, const sf::Color &col)
        : string(std::move(string)), color(col), pos(pos), size(size) {
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(color);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);
    text.setPosition(pos);
}

void Text::setString(const std::string &str) {
    string = str;
    text.setString(string);
}

void Text::setPos(const sf::Vector2f &position) {
    pos = position;
    text.setPosition(pos);
}

void Text::setSize(int newSize) {
    size = newSize;
    text.setCharacterSize(size);
}

std::string Text::getString() {
    if (string == text.getString())
        return string;
    else {
        std::cout << "Text::getString() error: string and text.getString() are different" << std::endl;
        return text.getString();
    }
}

sf::Vector2f Text::getPos() const {
    return pos;
}

void Text::draw(sf::RenderWindow &window) {
    window.draw(text);
}

