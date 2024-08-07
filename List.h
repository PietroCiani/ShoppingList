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

    void addProd(const std::string &name, const int &amount);

    void setAmount(Prod &prod, int newAmount);

    void setAmount(const std::string &name, int newAmount);

    Prod searchProd(const std::string& name);

    int searchProdIndex(const std::string& name);

    void update(Prod &prod, int diff);

    int getNumItems() const {
        return NumItems;
    }

    void printList() const;

    void removeProd(const Prod &prod);

private:
    std::string Name;
    std::vector<Prod> Items = {};
    unsigned short int NumItems;
};


#endif //SHOPPINGLIST_LIST_H
