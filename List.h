//
// Created by delta on 05/08/24.
//

#ifndef SHOPPINGLIST_LIST_H
#define SHOPPINGLIST_LIST_H

#include <iostream>
#include <list>
#include <memory>
#include "Prod.h"


class List {
public:
    explicit List(const std::string& name) : Name(name), NumItems(0) {}

    void addProd(Prod& prod) {
        prod.setList(std::make_shared<List>(*this));
        Items.push_back(prod);
        NumItems += prod.getAmount();
    }

    void removeProd(Prod prod) {
        Items.remove(prod); //FIXME: remove ?
        NumItems -= prod.getAmount();
        delete &prod;
    }

    void update() {
        NumItems = 0;
        for (const auto& prod : Items) {
            NumItems += prod.getAmount();
        }
    }

    int getNumItems() const {
        return NumItems;
    }

    void printList() const {
        std::cout << "Lista della spesa:" << std::endl;
        for (const auto& prod : Items) {
            std::cout << prod.getName() << ": " << prod.getAmount() << std::endl;
        }
        std::cout << "Totale oggetti: " << NumItems << std::endl;
    }

    ~List() {
        std::cout << "Distruggo lista e tutti i prodotti..." << std::endl;
        for (auto prod : Items) {
            delete &prod;
        }
    }
private:
    std::string Name;
    std::list<Prod> Items;
    unsigned short int NumItems;
};


#endif //SHOPPINGLIST_LIST_H
