//
// Created by delta on 05/08/24.
//

#include "List.h"
#include <algorithm>


void List::printList() const {
    std::cout << "Lista '"<< Name << "'" << std::endl;
    for (const auto & Item : Items){
        std::cout << Item->getName() << ": " << Item->getAmount() << std::endl;
    }
    std::cout << "Totale oggetti: " << NumItems << std::endl;
    std::cout << "--------------------" << std::endl;
}

void List::addProd(const Prod& prod) {
    Items.push_back(std::make_unique<Prod>(prod));
    Items.back()->setList(this);
    NumItems += prod.getAmount();
}

void List::addProd(const std::string &name, const int &amount = 1) {
    Prod prod(name, amount);
    addProd(prod);
}

void List::update(Prod &prod, int diff) {
    if (prod.getAmount() == 0) {
        removeProd(prod);
    }
    else {
        int index = searchProdIndex(prod.getName());
        if (index != -1) {
            NumItems += diff;
        }
    }
}

void List::removeProd(const Prod &prod) {
    std::cout << "Rimuovo " << prod.getAmount() << " '" << prod.getName() << "' dalla lista" << std::endl << std::endl;
    NumItems -= prod.getAmount();
    Items.erase(std::remove_if(Items.begin(), Items.end(), [&prod](const std::unique_ptr<Prod> &item) {
        return *item == prod;
    }), Items.end());
}

int List::searchProdIndex(const std::string &name) {
    for (int i = 0; i < Items.size(); i++) {
        if (Items[i]->getName() == name) {
            //std::cout << "'" << name << "' trovato!" << std::endl;
            return i;
        }
    }
    std::cout << "Prodotto '" << name << "' non trovato" << std::endl;
    return -1;
}

void List::setAmount(Prod &prod, int newAmount) {
    Items[searchProdIndex(prod.getName())]->setAmount(newAmount, true);
}

void List::setAmount(const std::string &name, int newAmount) {
    Items[searchProdIndex(name)]->setAmount(newAmount, true);
}

Prod &List::searchProd(const std::string &name) {
    return *Items[searchProdIndex(name)];
}

