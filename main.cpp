#include <SFML/Graphics.hpp>
#include "Prod.h"
#include "List.h"
#include "Button.h"

int main(){
    List shoppingList("Casa");
    shoppingList.addProd("Pane");
    shoppingList.addProd("Latte", 2);
    shoppingList.addProd("Uova", 6);

    // vectors to be drawn
    std::vector<std::unique_ptr<sf::Drawable>> drawables;
    std::vector<std::unique_ptr<Button>> buttons;

    sf::Vector2f w(300, 300);
    sf::RenderWindow window(sf::VideoMode(w.x,w.y), "Shopping List");

    sf::Color bg(40,40,40);
    sf::Color fg(251,241,199);

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        return -1;
    }

    while (window.isOpen()) {
        sf::Event event;
        window.clear(bg);

        Button test("+", {w.x * 0.5f, w.y * 0.5f},[&w](){std::cout << "window is " << w.x << " x " << w.y << std::endl;});
        buttons.push_back(std::make_unique<Button>(test));

        auto title = std::make_unique<sf::Text>();
        title->setFont(font);
        title->setString("Lista '"+ shoppingList.getName() +"'");
        title->setCharacterSize(24);
        title->setFillColor(fg);
        title->setPosition(w.x * 0.1, w.y * 0.1);
        drawables.push_back(std::move(title));

        float yPos = w.y * 0.25;
        // for each product in list create a text object and its buttons
        for (int i = 0; i < shoppingList.getItemsSize(); ++i) {
            Prod prod = shoppingList.getItems(i);
            auto text = std::make_unique<sf::Text>();
            text->setFont(font);
            text->setString(prod.getName() + ": " + std::to_string(prod.getAmount()));
            text->setCharacterSize(14);
            text->setFillColor(fg);
            text->setPosition(w.x * 0.12, yPos);

            Button increase("+", {w.x * 0.62f, yPos}, [&shoppingList, prod](){
                shoppingList.setAmount(prod.getName(), prod.getAmount() - 1);
            });
            Button decrease("-", {w.x * 0.82f, yPos}, [&shoppingList, prod](){
                shoppingList.setAmount(prod.getName(), prod.getAmount() + 1);
            });

            yPos += w.y * 0.1;

            drawables.push_back(std::move(text));
            buttons.push_back(std::make_unique<Button>(increase));
            buttons.push_back(std::make_unique<Button>(decrease));
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                for (auto& button : buttons) {
                    button->checkClicked(mousePos);
                }
            }
        }

        for (const auto& drawable : drawables) {
            window.draw(*drawable);
        }
        for (const auto& button : buttons) {
            button->draw(window);
        }
        window.display();
        drawables.clear();
        buttons.clear();
    }
    return 0;
};