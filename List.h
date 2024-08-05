//
// Created by delta on 05/08/24.
//

#ifndef SHOPPINGLIST_LIST_H
#define SHOPPINGLIST_LIST_H

#include <iostream>
#include <list>
#include <memory>
#include "Prod.h"

class Prod;

class List {
public:
    explicit List(const std::string& name) : Name(name), NumItems(0) {}

    void addProd(const Prod& prod);

    //void removeProd(Prod prod);

    void update();

    int getNumItems() const {
        return NumItems;
    }

    void printList() const;

    /*~List() {
        std::cout << "Distruggo lista e tutti i prodotti..." << std::endl;
        for (auto prod : Items) {
            delete &prod;
        }
    }*/
private:
    std::string Name;
    std::list<std::unique_ptr<Prod>> Items;
    unsigned short int NumItems;
};


#endif //SHOPPINGLIST_LIST_H
