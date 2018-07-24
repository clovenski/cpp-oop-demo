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
#include "CargoShip.h"
#include <iomanip>

int main() {
    const int ARRAY_SIZE = 15;

    // allocate memory
    Ship** shipArray = new Ship*[ARRAY_SIZE] {
        new Ship("ship1", "1990"),
        new Ship("ship2", "1991"),
        new Ship("ship3", "1980"),
        new Ship("ship4", "1960"),
        new Ship("ship5", "1995"),
        new CruiseShip("cruiseship1", "1994", 10),
        new CruiseShip("cruiseship2", "1934", 50),
        new CruiseShip("cruiseship3", "1804", 90),
        new CruiseShip("cruiseship4", "1999", 5),
        new CruiseShip("cruiseship5", "2000", 1),
        new CargoShip("cargoship1", "2003", 100),
        new CargoShip("cargoship2", "2018", 600),
        new CargoShip("cargoship3", "1987", 10),
        new CargoShip("cargoship4", "2004", 55),
        new CargoShip("cargoship5", "2007", 5000),
    };

    cout << "J. Tengco's Ship" << endl << endl;

    cout << "Iterate through an array of 15 pointers to Ship objects, invoking their print functions:" << endl;
    for(int i = 0; i < ARRAY_SIZE; i++) {
        // set width of 2, set fill to character zero; formatting for listing the array
        cout << setw(2) << setfill('0') << i + 1 << ". ";
        shipArray[i]->print();
        cout << endl;
    }
    cout << endl;

    Ship* ship1 = shipArray[0];
    cout << "Focus on 1st element in array: " << *ship1 << endl;
    cout << "Set its year to 2018" << endl;
    // arrow reference since ship1 variable is a pointer to Ship object; invoke its setYear function
    ship1->setYear("2018");
    cout << "Result: " << *ship1 << endl;
    cout << endl;

    // cast Ship pointer in array to CruiseShip pointer
    CruiseShip* cruiseShip1 = static_cast<CruiseShip*>(shipArray[5]);
    cout << "Focus on 6th element in array: " << *cruiseShip1 << endl;
    cout << "Add 12 more passenger capacity" << endl;
    // example of operator overload; overload the plus operator to a CruiseShip object -> adding passenger capacity
    *cruiseShip1 + 12;
    cout << "Result: " << *cruiseShip1 << endl << endl;

    // note the parentheses -> because postfix and prefix increment/decrement have precedence over dereference operator (*)
    cout << "Postfix increment demonstration: " << (*cruiseShip1)++ << endl;
    cout << "Result: " << *cruiseShip1 << endl << endl;

    cout << "Prefix decrement demonstration: " << --(*cruiseShip1) << endl;
    cout << "Result: " << *cruiseShip1 << endl;
    cout << endl;

    // use of friend operator to allow istream object cin to input information to CruiseShip object
    cout << "Please enter new information for this cruise ship." << endl;
    cin >> *cruiseShip1;
    cout << "Result: " << *cruiseShip1 << endl << endl;

    cout << "Final status of array:" << endl;
    for(int i = 0; i < ARRAY_SIZE; i++) {
        cout << setw(2) << setfill('0') << i + 1 << ". ";
        shipArray[i]->print();
        cout << endl;
    }

    // deallocate memory, each Ship pointer in the array was dynamically allocated so free each of them separately
    for(int i = 0; i < ARRAY_SIZE; i++)
        delete shipArray[i];

    // then free the dynamically allocated array of Ship pointers
    delete [] shipArray;
}
