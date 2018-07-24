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

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship {
    private:
        int capacity;
    public:
        CargoShip(string name, string year, int capacity);
        void setCapacity(int newCapacity);
        int getCapacity() const;
        void print() const;
        friend ostream &operator<<(ostream &lhs, const CargoShip &rhs);
};

#endif