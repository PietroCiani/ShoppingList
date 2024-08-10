#include <SFML/Graphics.hpp>
#include "Prod.h"
#include "List.h"

int main(){
    List shoppingList("Casa");
    shoppingList.addProd("Pane");
    shoppingList.addProd("Latte", 2);
    shoppingList.addProd("Uova", 6);

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
        std::vector<std::unique_ptr<sf::Drawable>> drawables;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(bg);

        auto title = std::make_unique<sf::Text>();
        title->setFont(font);
        title->setString("Lista '"+ shoppingList.getName() +"'");
        title->setCharacterSize(24);
        title->setFillColor(fg);
        title->setPosition(w.x * 0.1, w.y * 0.1);
        drawables.push_back(std::move(title));

        float yPos = w.y * 0.2;
        for (int i = 0; i < shoppingList.getItemsSize(); ++i) {
            Prod prod = shoppingList.getItems(i);
            auto text = std::make_unique<sf::Text>();
            text->setFont(font);
            text->setString(prod.getName() + ": " + std::to_string(prod.getAmount()));
            text->setCharacterSize(14);
            text->setFillColor(fg);
            text->setPosition(w.x * 0.12, yPos);
            yPos += w.y * 0.05;

            drawables.push_back(std::move(text));
        }

        for (const auto& drawable : drawables) {
            window.draw(*drawable);
        }
        window.display();
        drawables.clear();
    }
    return 0;
};