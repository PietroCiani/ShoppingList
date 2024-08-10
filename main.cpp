#include <SFML/Graphics.hpp>
#include "Prod.h"
#include "List.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }


    /*
    List list1("Casa");
    List list2("Grigliata");

    list1.addProd(Prod("Pane", 2));
    Prod latte("Latte");
    list1.addProd(latte);
    list1.addProd(Prod("Uova", 6));

    list2.addProd(Prod("Salsicce", 10));
    list2.addProd(Prod("Hamburger", 5));
    list2.addProd("Insalata",3);
    list2.addProd(Prod("Carbonella"));

    list1.setAmount("Uova", 10);
    list1.setAmount(latte, 2);
    list1.setAmount(latte, 1);
    list1.removeProd(latte);

    list1.printList();
     */

    return 0;
};