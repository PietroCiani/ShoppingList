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

class Prod : public std::enable_shared_from_this<Prod> {
public:
    explicit Prod(std::string name, int amount = 1, const std::shared_ptr<List>& lst = nullptr)
            : name(std::move(name)), amount(amount), list(lst) {}

    void setAmount(int newAmount);

    unsigned short int getAmount() const {
        return amount;
    }

    void NotifyList();

    std::string getName() const {
        return name;
    }

    void setList(const std::shared_ptr<List>& lst) { list = lst;}

private:
    std::string name;
    unsigned short int amount;
    std::weak_ptr<List> list;
};

#endif //SHOPPINGLIST_PROD_H
