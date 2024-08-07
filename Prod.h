//
// Created by delta on 05/08/24.
//

#ifndef SHOPPINGLIST_PROD_H
#define SHOPPINGLIST_PROD_H


#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <memory>

class List;

class Prod {
public:
    explicit Prod(std::string name, int amount = 1, List *lst = nullptr)
            : name(std::move(name)), amount(amount), list(lst) {}

    void setAmount(int newAmount);

    unsigned short int getAmount() const {
        return amount;
    }

    void NotifyList();

    std::string getName() const {
        return name;
    }

    void setList(List *lst) {
        list = lst; //FIXME: try to use smart ptr (shared?)
    }

    bool operator==(const Prod &other) const {
        return name == other.name;
    }

private:
    std::string name;
    unsigned short int amount;
    List* list;
};

#endif //SHOPPINGLIST_PROD_H
