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

#include "CargoShip.h"

// constructor; : Ship(name, year) is for invoking super class constructor with arguments
CargoShip::CargoShip(string name, string year, int capacity) : Ship(name, year) {
    if(capacity > 0)
        this->capacity = capacity;
    else {
        cout << "Invalid capacity given, defaulting to 1." << endl;
        this->capacity = 1;
    }
}

void CargoShip::setCapacity(int newCapacity) {
    if(newCapacity > 0)
        capacity = newCapacity;
}

int CargoShip::getCapacity() const {
    return capacity;
}

void CargoShip::print() const {
    cout << name << ", capacity of " << capacity;
}

ostream &operator<<(ostream &lhs, const CargoShip &rhs) {
    lhs << rhs.name << ", capacity of " << rhs.capacity;
    return lhs;
}
