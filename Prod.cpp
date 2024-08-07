//
// Created by delta on 05/08/24.
//

#include "Prod.h"
#include "List.h"

void Prod::NotifyList() {
    list->update(*this);
}

void Prod::setAmount(int newAmount) {
    std::cout << "Cambio quantità: " << amount << " -> " << newAmount << std::endl << std::endl;
    amount = newAmount;
    NotifyList();
    if (amount == 0) {
        //list.removeProd(this);
        //delete this;
    }
}

//Prod::~Prod() {
//    if (list) {
//        // se la lista possiede l'oggetto prod -> devo rimuovere l'oggetto dalla lista
//        list->removeProd(*this);
//    }
//}
