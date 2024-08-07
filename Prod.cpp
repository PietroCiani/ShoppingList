//
// Created by delta on 05/08/24.
//

#include "Prod.h"
#include "List.h"


void Prod::setAmount(int newAmount, bool updateList = true) {
    std::cout << "Cambio quantità: " << amount << " -> " << newAmount << std::endl << std::endl;
    int diff = newAmount - amount;
    amount = newAmount;
    if (list && updateList) {
        list->update(*this, diff);
    }
    if (amount == 0) {
        //list.removeProd(this);
        //delete this;
    }
}
