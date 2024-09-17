//
// Created by delta on 05/08/24.
//

#include "Prod.h"
#include "List.h"


void Prod::setNumber(int newNumber) {
    if (count) {
        std::cout << "Cambio quantità di '" << name << "':" << number << " -> " << newNumber << std::endl << std::endl;
        number = newNumber;
    } else {
        throw std::logic_error("Errore: Stai cercando di modificare la quantità di un prodotto !count: '" + name + "'");
    }
}

unsigned short int Prod::getNumber() const {
    return number;
}

std::string Prod::getName() const {
    return name;
}

void Prod::setCount(bool count) {
    Prod::count = count;
}

bool Prod::isCount() const {
    return count;
}

bool Prod::operator==(const Prod &other) const {
    return (name == other.name && number == other.number && count == other.count);
}