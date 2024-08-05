//
// Created by delta on 05/08/24.
//

#ifndef SHOPPINGLIST_PROD_H
#define SHOPPINGLIST_PROD_H


#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <list>
#include <memory>
#include "List.h"

class List;

class Prod {
public:
    Prod(std::string name, int amount = 1) : name(std::move(name)), amount(amount) {}

    void setAmount(int newAmount);

    int getAmount() const {
        return amount;
    }

    void setList(List *lst);

    void NotifyList();

    std::string getName() const {
        return name;
    }

private:
    std::string name;
    unsigned short int amount{};
    List *list;
};

#endif //SHOPPINGLIST_PROD_H
