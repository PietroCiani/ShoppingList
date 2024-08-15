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

int main(){
    List shoppingList("Casa");
    shoppingList.addProd("Uova", 6);
    shoppingList.addProd("Latte", 2);
    shoppingList.addProd("Pane");

    // vectors to be drawn
    std::vector<std::unique_ptr<Text>> texts;
    std::vector<std::shared_ptr<Button>> buttons;

    sf::Vector2f w(300, 400);
    sf::RenderWindow window(sf::VideoMode(w.x,w.y), "Shopping List");
    sf::View view = window.getView();
    view.setCenter(w.x / 2.f, w.y / 2.f);

    sf::Color bg(40,40,40);
    sf::Color fg(251,241,199);
    sf::Color fgDarker(168,153,132);

    sf::Font font;
    sf::Font fontBold;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
        return -1;
    if (!fontBold.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf"))
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
        Text textField(inputText, {w.x * 0.5f, w.y * lastRow + 15.f + scrollOffset}, font);
        float yPos = w.y * 0.35f + scrollOffset;

        texts.push_back(std::make_unique<Text>(insert));
        texts.push_back(std::make_unique<Text>(title));

        for (int i = 0; i < shoppingList.getItemsSize(); ++i) {
            Prod prod = shoppingList.getItems(i);
            Text text(prod.getName() + ": " + std::to_string(prod.getAmount()), {w.x * 0.2f, yPos+15.f}, font);
            Button increase("-", {w.x * 0.7f, yPos}, [&shoppingList, prod](){
                shoppingList.setAmount(prod.getName(), prod.getAmount() - 1);
            }, font);
            Button decrease("+", {w.x * 0.8f, yPos}, [&shoppingList, prod](){
                shoppingList.setAmount(prod.getName(), prod.getAmount() + 1);
            }, font);

            yPos += step;

            texts.push_back(std::make_unique<Text>(text));
            buttons.push_back(std::make_unique<Button>(increase));
            buttons.push_back(std::make_unique<Button>(decrease));
        }

        Button addToList("Aggiungi", {w.x * 0.75f - 20, w.y * lastRow}, [&shoppingList, &inputText](){
            if (!inputText.empty()){
                int prodIndex = shoppingList.searchProdIndex(inputText);
                std::cout << "Cerco " << inputText << " nella lista" << std::endl;
                if (prodIndex == -1) {
                    std::cout << inputText << " non c'è -> aggiungo" << std::endl;
                    shoppingList.addProd(capitalizeFirstLetter(inputText));
                    inputText.clear();
                } else {
                    std::cout << shoppingList.getItems(prodIndex).getName() << " è gia nella lista (+1)" << std::endl;
                    shoppingList.getItems(prodIndex).setAmount(shoppingList.getItems(prodIndex).getAmount()+1, true);
                    inputText.clear();
                }
            }
        }, font, {70,30});
        buttons.push_back(std::make_unique<Button>(addToList));

        while (window.pollEvent(event)){
            InputManager::checkInput(window, event, buttons, view, w, textField, inputText, addToList, scrollOffset, step);
        }

        texts.push_back(std::make_unique<Text>(textField));

        for (const auto& txt : texts) {
            txt->draw(window);
        }
        for (const auto& button : buttons) {
            button->draw(window);
        }
        window.display();
        texts.clear();
        buttons.clear();
    }
    return 0;
}