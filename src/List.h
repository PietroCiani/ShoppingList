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

    void addProd(const std::string &name, const int &amount = 1);

    void setAmount(Prod &prod, int newAmount);

    void setAmount(const std::string &name, int newAmount);

    std::string getName();

    Prod &searchProd(const std::string &name); //FIXME return array of prod

    int searchProdIndex(const std::string& name); //FIXME handle empty no results (empty array in searchProd)

    Prod & getItems(int index);

    void update(Prod &prod, int diff);

    int getItemsSize() const {
        return Items.size();
    }

    void printList() const;

    void removeProd(const Prod &prod);

private:
    std::string Name;
    std::vector<std::unique_ptr<Prod>> Items = {};
    unsigned short int NumItems;
};


#endif //SHOPPINGLIST_LIST_H
