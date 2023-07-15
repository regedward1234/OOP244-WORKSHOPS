/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description: 
// 
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/14      Create a MotorVehicle class that holds information about a vehicle
//Reginald         2023/07/15      Added const to ostream helper function as it should not be changed
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__
#define LICENSE_PLATE 9
#define ADDRESS_SIZE 64
#include <iostream>

using namespace std;
namespace sdds {
	class MotorVehicle {
		char licensePlate[LICENSE_PLATE];
		char address[ADDRESS_SIZE];
		int year;
	public:
		// constructor to set license and year
		MotorVehicle(const char* license, int years);
		// move vechicle to new address if new is different
		void moveTo(const char* newAddress);
		// a query that places into os the content of the object
		ostream& write(ostream& os) const;
		// a mutator that reads from stream
		istream& read(istream& in);
	};

	// insert vehicle into a stream
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
	// extract vehicle from stream
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle);

}

#endif
