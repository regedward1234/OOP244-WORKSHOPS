/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description:
// Name: Reginald Edward
// Email: redward7@myseneca.ca
// Student Number: 149047227
// Date: July 14, 2023
// Section: OOP244 NAA
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/14      Create a Truck class that inherits from MotorVehicle
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include "MotorVehicle.h"

namespace sdds {
	// inherit the structure of the base class MotorVehcile
	class Truck : public MotorVehicle {
		double weightCapacity;
		double currentCargoLoad;
	public: 
		// Use incoming arguments to initialize object
		Truck(const char* licensePlate, int year, double weightCapacity, const char* address);
		// add to current cargo, if current load has been changed return true
		bool addCargo(double cargo);
		// unload cargo if cargo has changed then return true
		bool unloadCargo();
		// display to screen
		ostream& write(ostream& os);
		// read from user input
		istream& read(istream& in);
	};
	// return truck write function using overloaded operator
	std::ostream& operator<<(std::ostream& os, Truck& truck);
	//return truck read function using overloaded operator
	std::istream& operator>>(std::istream& in, Truck& truck);
}



#endif