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

#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include "Ship.h"

class CruiseShip : public Ship {
    private:
        int maxPassengers;
    public:
        CruiseShip(string name, string year, int maxPassengers);
        void setMaxPassengers(int newMax);
        int getMaxPassengers() const;
        void print() const;
        friend ostream& operator<<(ostream &lhs, const CruiseShip &rhs);
        friend istream& operator>>(istream &lhs, CruiseShip &rhs);
        void operator+(int n);
        CruiseShip& operator--();
        CruiseShip& operator++();
        CruiseShip operator++(int);
        CruiseShip operator--(int);
};

#endif