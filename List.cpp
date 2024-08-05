//
// Created by delta on 05/08/24.
//

#include "List.h"

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
    Items.back()->setList(this);
    NumItems += prod.getAmount();
}

void List::update() {
    NumItems = 0;
    for (const auto& prod : Items) {
        NumItems += prod->getAmount();
    }
}

/*void List::removeProd(Prod prod) {
        Items.remove(prod); //FIXME: remove ?
        NumItems -= prod.getAmount();
        delete &prod;
}*/
