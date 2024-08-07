//
// Created by delta on 05/08/24.
//

#include "List.h"
#include <algorithm>


void List::printList() const {
    std::cout << "Lista '"<< Name << "'" << std::endl;
    for (const auto & Item : Items){
        std::cout << Item.getName() << ": " << Item.getAmount() << std::endl;
    }
    std::cout << "Totale oggetti: " << NumItems << std::endl;
    std::cout << "--------------------" << std::endl;
}

void List::addProd(const Prod& prod) {
    Items.push_back(prod);
    Items.back().setList(this);
    NumItems += prod.getAmount();
}

void List::addProd(const std::string &name, const int &amount) {
    Prod prod(name, amount);
    addProd(prod);
}

void List::update(Prod &prod, int diff) {
    if (prod.getAmount() == 0) {
        removeProd(prod);
    }
    else {
        //FIXME: avoid loops
        int index = searchProdIndex(prod.getName());
        if (index != -1) {
            Items[index].setAmount(prod.getAmount(), false);
            NumItems += diff;
        }
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

int List::searchProdIndex(const std::string &name) {
    for (int i = 0; i < Items.size(); i++) {
        if (Items[i].getName() == name) {
            std::cout << "'" << name << "' trovato!" << std::endl;
            return i;
        }
    }
    std::cout << "Prodotto non trovato" << std::endl;
}

void List::setAmount(Prod &prod, int newAmount) {
    searchProd(prod.getName()).setAmount(newAmount, true);
}

void List::setAmount(const std::string &name, int newAmount) {
    searchProd(name).setAmount(newAmount, true);
}

