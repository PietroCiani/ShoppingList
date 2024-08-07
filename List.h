//
// Created by delta on 05/08/24.
//

#ifndef SHOPPINGLIST_LIST_H
#define SHOPPINGLIST_LIST_H

#include <iostream>
#include <list>
#include <memory>
#include <vector>
#include "Prod.h"

class Prod;

class List : public std::enable_shared_from_this<List> {
public:
    explicit List(const std::string &name) : Name(name), NumItems(0) {}

    void addProd(const Prod& prod);

    void setAmount(const std::string& name, int amount);

    std::shared_ptr<Prod> searchProd(const std::string& name);

    void update(std::shared_ptr<Prod> prod);

    int getNumItems() const {
        return NumItems;
    }

    void printList() const;

//    void removeProd(const std::string &name);
//
    void removeProd(std::shared_ptr<Prod> prod);

    /*~List() {
        std::cout << "Distruggo lista e tutti i prodotti..." << std::endl;
        for (auto prod : Items) {
            delete &prod;
        }
    }*/
private:
    std::string Name;
    std::vector<std::shared_ptr<Prod>> Items;
    unsigned short int NumItems;


};


#endif //SHOPPINGLIST_LIST_H
