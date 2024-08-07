//
// Created by delta on 05/08/24.
//

#include "List.h"
#include <algorithm>


void List::printList() const {
    std::cout << "Lista '"<< Name << "'" << std::endl;
    for (const auto& prod : Items) {
        std::cout << prod->getName() << ": " << prod->getAmount() << std::endl;
    }
    std::cout << "Totale oggetti: " << NumItems << std::endl;
    std::cout << "--------------------" << std::endl;
}

void List::addProd(const Prod& prod) {
    Items.push_back(std::make_unique<Prod>(prod));
    Items.back()->setList(shared_from_this());
    NumItems += prod.getAmount();
}

void List::update(std::shared_ptr<Prod> prod) {
    if (prod->getAmount() == 0) {
        removeProd(prod);
    }
    else {
        NumItems += prod->getAmount();
    }
}

void List::setAmount(const std::string& name, int newAmount) {
    auto prod = searchProd(name);
    prod->setAmount(newAmount);
}

//void List::removeProd(const std::string &name) {
//    auto prod = searchProd(name);
//    std::cout << "Rimuovo " << (*prod).getAmount() << " '" << name << "' dalla lista" << std::endl << std::endl;
//    NumItems -= (*prod).getAmount();
//    Items.remove(prod);
//}
//
//void List::removeProd(Prod &prod) {
//    std::cout << "Rimuovo " << prod.getAmount() << " '" << prod.getName() << "' dalla lista" << std::endl << std::endl;
//    NumItems -= prod.getAmount();
//    Items.remove_if([&prod](const std::unique_ptr<Prod>& p) { return p.get() == &prod; });
//    // la lambda function ritorna true se l'oggetto puntato da p è uguale al prod che dobbiamo rimuovere
//}

std::shared_ptr<Prod> List::searchProd(const std::string &name) {
    for (auto & prod : Items) {
        if (prod->getName() == name) {
            std::cout << "'" << name << "' trovato!" << std::endl;
            return std::move(prod);
        }
    }
    std::cout << "Prodotto non trovato" << std::endl;
    return nullptr;
}

void List::removeProd(std::shared_ptr<Prod> prod) {
    std::cout << "Rimuovo " << prod->getAmount() << " '" << prod->getName() << "' dalla lista" << std::endl << std::endl;
    Items.erase(
            std::remove_if(Items.begin(), Items.end(),
                           [&prod](const std::shared_ptr<Prod>& p) {
                               return p->getName() == prod->getName();
                           }),
            Items.end()
    );
}

