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

#include "CruiseShip.h"

CruiseShip::CruiseShip(string name, string year, int maxPassengers) : Ship(name, year) {
    if(maxPassengers > 0)
        this->maxPassengers =  maxPassengers;
    else {
        cout << "Invalid max passengers given, defaulting to 1." << endl;
        this->maxPassengers = 1;
    }
}

void CruiseShip::setMaxPassengers(int newMax) {
    if(newMax > 0)
        maxPassengers = newMax;
}

int CruiseShip::getMaxPassengers() const {
    return maxPassengers;
}

void CruiseShip::print() const {
    cout << name << ", " << maxPassengers << " max passenger" << (maxPassengers > 1 ? "s" : "");
}

ostream& operator<<(ostream &lhs, const CruiseShip &rhs) {
    lhs << rhs.name << ", " << rhs.maxPassengers << " max passenger" << (rhs.maxPassengers > 1 ? "s" : "");
    return lhs;
}

istream& operator>>(istream &lhs, CruiseShip &rhs) {
    string name;
    string year;
    int maxPassengers;

    cout << "Enter the name: ";
    // getline function to capture entire string user inputs up to newline character
    getline(lhs, name);
    cout << "Enter the year: ";
    getline(lhs, year);
    cout << "Enter the maximum passengers: ";
    lhs >> maxPassengers;
    rhs.setName(name);
    rhs.setYear(year);
    rhs.setMaxPassengers(maxPassengers);
    return lhs;
}

void CruiseShip::operator+(int n) {
    maxPassengers += n;
}

CruiseShip& CruiseShip::operator++() {
    maxPassengers += 1;
    // remember that "this" is a pointer
    return *this;
}

CruiseShip& CruiseShip::operator--() {
    maxPassengers -= 1;
    return *this;
}

// for postfix, create a temp copy of this CruiseShip, perform postfix operation, and return the temp - the previous state of the object
CruiseShip CruiseShip::operator++(int) {
    CruiseShip temp(name, year, maxPassengers);
    maxPassengers += 1;
    return temp;
}

// note the int as parameter -> needed for postfix operator overload
CruiseShip CruiseShip::operator--(int) {
    CruiseShip temp(name, year, maxPassengers);
    maxPassengers -= 1;
    return temp;
}