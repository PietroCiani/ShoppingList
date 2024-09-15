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
    explicit Prod(const std::string &name) : name(name), number(1), count(false) {}

    Prod(const std::string &name, unsigned short int number) : name(name), number(number), count(true) {}

    void setNumber(int newNumber);

    unsigned short int getNumber() const;

    std::string getName() const;

    bool isCount() const;

    bool operator==(const Prod &other) const;

private:
    std::string name;
    bool count;
    unsigned short int number;
};

#endif //SHOPPINGLIST_PROD_H
