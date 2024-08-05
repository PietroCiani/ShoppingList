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

class List;

class Prod {
public:
    Prod(const std::string& name, std::shared_ptr<List> lst, int amount = 1)
    : name(name), list(std::move(lst)), amount(amount) {}

    void setAmount(int newAmount) {
        amount = newAmount;
        NotifyList();
        if (amount == 0) {
            list.removeProd(this);
            delete this;
        }
    }

    int getAmount() const {
        return amount;
    }

    void setList(std::shared_ptr<List> lst) {
        list = std::move(lst);
    }

    void NotifyList();

    std::string getName() const {
        return name;
    }
private:
    std::string name;
    unsigned short int amount;
    std::shared_ptr<List> list;
};


#endif //SHOPPINGLIST_PROD_H
