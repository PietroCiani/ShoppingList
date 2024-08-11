//
// Created by delta on 10/08/24.
//

#ifndef SHOPPINGLIST_BUTTON_H
#define SHOPPINGLIST_BUTTON_H


#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    explicit Button(const std::string &text, sf::Vector2f pos, sf::Vector2f size = {40.f, 20.f});

    void setPosition(sf::Vector2f pos);

    void setSize(sf::Vector2f size);

    void checkClicked(const sf::Vector2f& mousePos);

    void enable();

    void draw(sf::RenderWindow &window);

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font;
    sf::Vector2f pos;
    sf::Vector2f size;
};

#endif //SHOPPINGLIST_BUTTON_H
