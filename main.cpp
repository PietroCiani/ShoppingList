#include <SFML/Graphics.hpp>
#include "src/Prod.h"
#include "src/List.h"
#include "src/Button.h"
#include "src/Text.h"
#include "src/InputManager.h"

std::string capitalizeFirstLetter(const std::string& str) {
    if (str.empty()) {
        return str;
    }
    std::string capitalized = str;
    capitalized[0] = std::toupper(capitalized[0]);
    std::transform(capitalized.begin() + 1, capitalized.end(), capitalized.begin() + 1, ::tolower);
    return capitalized;
}

std::vector<int> findButtonIndices(const std::vector<std::unique_ptr<sf::Drawable>>& drawables) {
    std::vector<int> buttonIndices;
    for (int i = 0; i < drawables.size(); ++i) {
        if (dynamic_cast<Button*>(drawables[i].get())) {
            buttonIndices.push_back(i);
        }
    }
    return buttonIndices;
}


int main(){
    List shoppingList("Casa");
    shoppingList.addProd("Uova", 6);
    shoppingList.addProd("Latte", 2);
    shoppingList.addProd("Pane");

    std::vector<std::unique_ptr<sf::Drawable>> drawables;

    sf::Vector2f w(300, 400);
    sf::RenderWindow window(sf::VideoMode(w.x,w.y), "Shopping List");
    sf::View view = window.getView();
    view.setCenter(w.x / 2.f, w.y / 2.f);

    sf::Color bg(40,40,40);
    sf::Color bgLighter(80,73,69);
    sf::Color bgDarker(29,32,33);
    sf::Color fg(251,241,199);
    sf::Color fgDarker(168,153,132);

    sf::Font font;
    sf::Font fontBold;
    if (!font.loadFromFile("/Volumes/Macintosh HD/System/Library/Fonts/Supplemental/Arial Unicode.ttf"))
        return -1;
    if (!fontBold.loadFromFile("/Volumes/Macintosh HD/System/Library/Fonts/Supplemental/Arial Bold.ttf"))
        return -1;

    std::string inputText;
    float scrollOffset = 0.f;
    float step = w.y * 0.1f;
    float lastRow = 0.8;

    while (window.isOpen()) {
        sf::Event event{};
        window.clear(bg);
        Text title("Lista '" + shoppingList.getName() + "'", {w.x * 0.5f, w.y * 0.1f + scrollOffset}, fontBold, 24);
        Text insert("Scrivi un prodotto e premi Invio", {w.x*0.5f, w.y * 0.23f + scrollOffset}, font, 14, fgDarker);
        Text textField(inputText, {w.x * 0.5f, w.y * lastRow + 15.f}, font);
        bool searching = !inputText.empty();
        std::vector<int> found = shoppingList.searchProdIndex(inputText);
        float yPos = w.y * 0.35f + scrollOffset;

        drawables.push_back(std::make_unique<Text>(insert));
        drawables.push_back(std::make_unique<Text>(title));

        if(!searching) {
            // Print full list
            for (int i = 0; i < shoppingList.getItemsSize(); ++i) {
                Prod& prod = shoppingList.getItems(i);
                Text text(prod.getName() + ": " + std::to_string(prod.getNumber()), {w.x * 0.2f, yPos+15.f}, font);
                if (prod.isCount()){
                    Button decrease("-", {w.x * 0.7f, yPos}, [&shoppingList, prod, i](){
                        shoppingList.setNumber(i, prod.getNumber() - 1);
                    }, font);
                    Button increase("+", {w.x * 0.8f, yPos}, [&shoppingList, prod, i](){
                        shoppingList.setNumber(i, prod.getNumber() + 1);
                    }, font);
                    drawables.push_back(std::make_unique<Button>(decrease));
                    drawables.push_back(std::make_unique<Button>(increase));
                }
                Button remove("x", {w.x * 0.9f, yPos}, [&shoppingList, i](){
                        shoppingList.removeProd(i);
                    }, font);

                yPos += step;

                drawables.push_back(std::make_unique<Text>(text));
                drawables.push_back(std::make_unique<Button>(remove));
            }
        } else {
            // Print search results
            for (int i = 0; i < found.size(); ++i) {
                Prod& prod = shoppingList.getItems(found[i]);
                Text text(prod.getName() + ": " + std::to_string(prod.getNumber()), {w.x * 0.2f, yPos+15.f}, font);
                if (prod.isCount()){
                    Button decrease("-", {w.x * 0.7f, yPos}, [&shoppingList, prod, i](){
                        shoppingList.setNumber(i, prod.getNumber() - 1);
                    }, font);
                    Button increase("+", {w.x * 0.8f, yPos}, [&shoppingList, prod, i](){
                        shoppingList.setNumber(i, prod.getNumber() + 1);
                    }, font);
                    drawables.push_back(std::make_unique<Button>(decrease));
                    drawables.push_back(std::make_unique<Button>(increase));
                }
                Button remove("x", {w.x * 0.9f, yPos}, [&shoppingList, found, i](){
                    shoppingList.removeProd(found[i]);
                }, font);

                yPos += step;
                drawables.push_back(std::make_unique<Text>(text));
                drawables.push_back(std::make_unique<Button>(remove));
            }
        }

        sf::RectangleShape bottomRect({w.x, 100.f});
        bottomRect.setPosition({0, w.y*lastRow - 10.f});
        bottomRect.setFillColor(bg);
        drawables.push_back(std::make_unique<sf::RectangleShape>(bottomRect));

        Button addToList("Aggiungi", {w.x * 0.75f - 20, w.y * lastRow}, [&shoppingList, &inputText, searching, found](){
            if (searching){
                if (found.empty()) {
                    std::cout << inputText << " non c'è -> aggiungo" << std::endl;
                    shoppingList.addProd(capitalizeFirstLetter(inputText));
                    inputText.clear();
                } else if (found.size() == 1) {
                    std::cout << shoppingList.getItems(found[0]).getName() << " è gia nella lista (+1)" << std::endl;
                    shoppingList.getItems(found[0]).setNumber(shoppingList.getItems(found[0]).getNumber()+1);
                    inputText.clear();
                } else {
                    std::cout << "Trovati " << found.size() << " prodotti simili:" << std::endl;
                }
            }
        }, font, {70,30});
        drawables.push_back(std::make_unique<Button>(addToList));

        auto buttons = findButtonIndices(drawables);
        while (window.pollEvent(event)){
            InputManager::checkInput(window, event, drawables, buttons, view, w, textField, inputText, addToList,
                                     scrollOffset, step);
        }
        drawables.push_back(std::make_unique<Text>(textField));

        for (const auto& drawable : drawables) {
            window.draw(*drawable);
        }
        window.display();
        drawables.clear();
    }
    return 0;
}