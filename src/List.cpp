//
// Created by delta on 05/08/24.
//

#include "List.h"
#include <algorithm>


void List::printList() const {
    std::cout << "Lista '"<< Name << "'" << std::endl;
    for (const auto & Item : Items){
        std::cout << Item->getName() << ": " << Item->getNumber() << std::endl;
    }
    std::cout << "Totale oggetti: " << NumItems << std::endl;
    std::cout << "--------------------" << std::endl;
}

void List::addProd(const Prod& prod) {
    Items.push_back(std::make_unique<Prod>(prod));
    NumItems += prod.getNumber();
}

void List::addProd(const std::string &name, const int &amount) {
    Prod prod(name, amount);
    addProd(prod);
}

void List::update(int i, int diff) {
    if (Items[i]->getNumber() == 0) {
        removeProd(i);
    } else {
        NumItems += diff;
    }
}

void List::removeProd(int i) {
    std::cout << "Rimuovo " << Items[i]->getNumber() << " '" << Items[i]->getName() << "' dalla lista" << std::endl << std::endl;
    NumItems -= Items[i]->getNumber();
    Items.erase(Items.begin() + i);
}

std::vector<int> List::searchProdIndex(const std::string &name) {
    std::vector<int> results{};
    for (int i = 0; i < Items.size(); ++i) {
        if (Items[i]->getName().rfind(name, 0) == 0) { // rfind(name, 0) == 0 controlla se inizia con "name"
            results.push_back(i);
        }
    }
    return results;
}

Prod & List::getItems(int index) {
    return *Items[index];
}

void List::setNumber(int i, int newNumber) {
    int diff = newNumber - Items[i]->getNumber();
    Items[i]->setNumber(newNumber);
    update(i, diff);
}

std::string List::getName() {
    return Name;
}

