//
// Name: Tengco, Joel
// Course: cs-256-02-sp18
//
// Description:
// Implement Programming Challenges #12 in course textbook. Create a super class, Ship,
// which will have two subclasses, CargoShip and CruiseShip. Demonstrate these classes
// with an array of pointers to Ship objects, with the array also containing CruiseShip
// and CargoShip objects; demonstrating polymorphism.
//

#include "Ship.h"

Ship::Ship(string name, string year) {
    this->name = name;
    this->year = year;
}

void Ship::setName(string newName) {
    name = newName;
}

void Ship::setYear(string newYear) {
    year = newYear;
}

string Ship::getName() const {
    return name;
}

string Ship::getYear() const {
    return year;
}

void Ship::print() const {
    cout << name << ", " << year;
}

ostream &operator<<(ostream &lhs, const Ship &rhs) {
    lhs << rhs.name << ", " << rhs.year;
    return lhs;
}