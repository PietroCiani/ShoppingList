//
// Created by delta on 05/08/24.
//

#include "List.h"
#include <algorithm>

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void List::printList() const {
    std::cout << "Lista '"<< Name << "'" << std::endl;
    for (const auto & Item : Items){
        std::cout << Item->getName() << ": " << Item->getNumber() << std::endl;
    }
    std::cout << "Totale oggetti: " << NumItems << std::endl;
    std::cout << "--------------------" << std::endl;
}

void List::addProd(const std::string &name, const int &amount) {
    Prod prod(name, amount);
    Items.push_back(std::make_unique<Prod>(prod));
    NumItems += prod.getNumber();
}

void List::update(int i, int diff) {
    if (Items[i]->getNumber() == 0 && Items[i]->isCount()) {
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
        if (toLower(Items[i]->getName()).rfind(toLower(name), 0) == 0) {
            results.push_back(i);
        }
    }
    return results;
}

Prod & List::getItems(int index) {
    return *Items[index];
}

void List::setNumber(int i, int newNumber) {
    Items[i]->setCount(true);
    int diff = newNumber - Items[i]->getNumber();
    Items[i]->setNumber(newNumber);
    update(i, diff);


}

std::string List::getName() {
    return Name;
}

