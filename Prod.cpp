//
// Created by delta on 05/08/24.
//

#include "Prod.h"

void Prod::NotifyList() {
    list->update();
}

void Prod::setAmount(int newAmount) {
    amount = newAmount;
    NotifyList();
    if (amount == 0) {
        //list.removeProd(this);
        delete this;
    }
}

void Prod::setList(List *lst) {
    list = lst;
}