//
// Created by delta on 15/08/24.
//

#ifndef SHOPPINGLIST_INPUTMANAGER_H
#define SHOPPINGLIST_INPUTMANAGER_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Text.h"
#include <memory>

class InputManager {
public:
    static void checkInput(sf::RenderWindow &window, sf::Event event, const std::vector<std::unique_ptr<sf::Drawable>>& drawables,
                           std::vector<int> &buttons, sf::View &view, sf::Vector2f &w, Text &textField,
                           std::string &inputText, Button &addToList, float &scrollOffset, float step);
};


#endif //SHOPPINGLIST_INPUTMANAGER_H
