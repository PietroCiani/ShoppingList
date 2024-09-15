//
// Created by delta on 05/08/24.
//

#include "Prod.h"
#include "List.h"


void Prod::setNumber(int newNumber) {
    std::cout << "Cambio quantità di '" << name << "':" << number << " -> " << newNumber << std::endl << std::endl;
    int diff = newNumber - number;
    number = newNumber;
}

unsigned short int Prod::getNumber() const {
    return number;
}

std::string Prod::getName() const {
    return name;
}

bool Prod::isCount() const {
    return count;
}

bool Prod::operator==(const Prod &other) const {
    return name == other.name;
}