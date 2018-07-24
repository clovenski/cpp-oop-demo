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

#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>
using namespace std;

class Ship {
    private:
    protected:
        string name;
        string year;
    public:
        // constructor
        Ship(string name, string year);
        // setter functions
        void setName(string newName);
        void setYear(string newYear);
        // getter functions; note the const -> meaning the function does not modify the object
        string getName() const;
        string getYear() const;
        // function to print info of ship; note the virtual -> meaning subclasses are expected to override
        virtual void print() const;
        // friend function -> meaning entities outside of class can access fields
        friend ostream &operator<<(ostream &lhs, const Ship &rhs);
};

#endif