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
    explicit Prod(const std::string &name, int amount = 1, List *lst = nullptr)
            : name(name), amount(amount), list(lst) {}

    void setAmount(int newAmount, bool updateList);

    unsigned short int getAmount() const {
        return amount;
    }

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
    List* list; //FIXME smart pointer

};

#endif //SHOPPINGLIST_PROD_H
