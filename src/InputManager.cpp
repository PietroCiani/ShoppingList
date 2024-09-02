//
// Created by delta on 15/08/24.
//

#include "InputManager.h"

void InputManager::checkInput(sf::RenderWindow &window, sf::Event event, const std::vector<std::unique_ptr<sf::Drawable>>& drawables,
                              std::vector<int> &buttons, sf::View &view, sf::Vector2f &w, Text &textField,
                              std::string &inputText, Button &addToList, float &scrollOffset, float step) {
    //FIXME: switch/case?
    if (event.type == sf::Event::Closed) window.close();
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        for (auto& drawable : drawables) {
            Button* button = dynamic_cast<Button*>(drawable.get());
            if (button) {
                button->checkClicked(mousePos);
            }
        }
    }
    if (event.type == sf::Event::Resized) {
        view.setSize(float(event.size.width), float(event.size.height));
        view.setCenter(float(event.size.width) / 2.f, float(event.size.height) / 2.f);
        window.setView(view);
        w = {static_cast<float>(event.size.width), static_cast<float>(event.size.height)};
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b') {
            if (!inputText.empty()) {
                inputText.pop_back();
            }
        } else if (event.text.unicode == '\r') {
            addToList.clicked();
        } else {
            inputText += static_cast<char>(event.text.unicode);
        }
        textField.setString(inputText);
    }
    if (event.type == sf::Event::MouseWheelScrolled) {
        float scrollStep = event.mouseWheelScroll.delta * step;
        float newOffset = scrollOffset+scrollStep;
        if (newOffset > -(w.y+(w.y*0.35)) && newOffset <= 0){
            scrollOffset = newOffset;
        }
    }
}
