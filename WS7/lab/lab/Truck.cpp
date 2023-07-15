/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description:Add a derived class
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/14      Implement the functions for truck class
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include "Truck.h"

using namespace std;

namespace sdds {
	// constructor to set the values with parameters passed into it
	Truck::Truck(const char* licensePlate, int year, double weightCapacity, const char* address) : MotorVehicle(licensePlate, year),
		weightCapacity(weightCapacity), currentCargoLoad(0.0) {
		moveTo(address);
	}

	// add to current cargo, if current load has been changed return true
	bool Truck::addCargo(double cargo) {
		double availableRoom;
		bool temp;
		// get total of cargo if cargo added to current cargo
		availableRoom = weightCapacity - currentCargoLoad;
		// if it is less than max cargo add it and return true that a change took place
		if (availableRoom == 0) {
			temp = false;
		}
		else {
			if (availableRoom >= cargo) {
				currentCargoLoad += cargo;

			}
			else {
				currentCargoLoad += availableRoom;

			}
			temp = true;
		}
		return temp;
	}

	bool Truck::unloadCargo() {
		bool temp;

		// if currentload greater than 0 then set it to and set bool to true
		if (currentCargoLoad > 0) {
			currentCargoLoad = 0;
			temp = true;
		}
		else {
			temp = false;
		}

		return temp;
	}

	// output to screen
	ostream& Truck::write(ostream& os) {
		MotorVehicle::write(os);
		os << " | " << currentCargoLoad << "/" << weightCapacity << endl;
		return os;
	}

	// read from user input
	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> weightCapacity;
		cout << "Cargo: ";
		in >> currentCargoLoad;
		return in;
	}

	// return truck write function using overloaded operator
	std::ostream& operator<<(std::ostream& os, Truck& truck) {
		return truck.write(os);
	}

	//return truck read function using overloaded operator
	std::istream& operator>>(std::istream& in, Truck& truck) {
		return truck.read(in);
	}
}