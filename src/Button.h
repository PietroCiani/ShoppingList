//
// Created by delta on 10/08/24.
//

#ifndef SHOPPINGLIST_BUTTON_H
#define SHOPPINGLIST_BUTTON_H


#include <SFML/Graphics.hpp>
#include <string>
#include <functional>


class Button : public sf::Drawable {
public:
    explicit Button(const std::string &text, sf::Vector2f pos, std::function<void()> callback, const sf::Font& font,
                    sf::Vector2f size = {26.f, 26.f});

    void setPosition(sf::Vector2f pos);

    void setSize(sf::Vector2f size);

    void checkClicked(const sf::Vector2f& mousePos);

    void clicked();

    void setCallback(std::function<void()> callback);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font;
    sf::Vector2f pos;
    sf::Vector2f size;
    std::function<void()> onClickCallback;

};

#endif //SHOPPINGLIST_BUTTON_H
