//
// Created by delta on 05/08/24.
//

#include "List.h"
#include <algorithm>


void List::printList() const {
    std::cout << "Lista '"<< Name << "'" << std::endl;
    for (const auto& prod : Items) {
        std::cout << prod.getName() << ": " << prod.getAmount() << std::endl;
    }
    std::cout << "Totale oggetti: " << NumItems << std::endl;
    std::cout << "--------------------" << std::endl;
}

void List::addProd(const Prod& prod) {
    Items.push_back(prod);
    Items.back().setList(this);
    NumItems += prod.getAmount();
}

void List::update(Prod &prod) {
    if (prod.getAmount() == 0) {
        removeProd(prod);
    }
    else {
        NumItems += prod.getAmount();
    }
}

void List::removeProd(const Prod &prod) {
    std::cout << "Rimuovo " << prod.getAmount() << " '" << prod.getName() << "' dalla lista" << std::endl << std::endl;
    Items.erase(std::remove(Items.begin(), Items.end(), prod), Items.end());
}

Prod List::searchProd(const std::string &name) {
    for (auto & prod : Items) {
        if (prod.getName() == name) {
            std::cout << "'" << name << "' trovato!" << std::endl;
            return prod;
        }
    }
    std::cout << "Prodotto non trovato" << std::endl;
}

void List::setAmount(Prod &prod, int newAmount) {
    this->searchProd(prod.getName()).setAmount(newAmount);
}

