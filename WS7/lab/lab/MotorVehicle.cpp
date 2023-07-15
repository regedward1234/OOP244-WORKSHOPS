/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// Name: Reginald Edward
// Email: redward7@myseneca.ca
// Student Number: 149047227
// Date: July 14, 2023
// Section: OOP244 NAA
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/14      Implement the functions 
//Reginald         2023/07/15      Added const to ostream helper function as it should not be changed
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MotorVehicle.h"
#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds {
	// constructor to initialize the object with incoming arguments
	MotorVehicle::MotorVehicle(const char* license, int years) {
		if (license != nullptr) {
			year = years;
			strnCpy(licensePlate, license, 8);
			licensePlate[8] = '\0';
			strnCpy(address, "Factory", 64);
			address[64] = '\0';
		}
	}

	// replace the address with new address if its different and display to screen
	void MotorVehicle::moveTo(const char* newAddress) {
		if (strCmp(address, newAddress) != 0) {
			cout << "|";
			cout.width(8);
			cout.setf(ios::right);
			cout << licensePlate;
			cout.unsetf(ios::right);
			cout << "| |";
			cout.width(20);
			cout.setf(ios::right);
			cout << address;
			cout.unsetf(ios::right);
			cout << " ---> ";
			cout.width(20);
			cout.setf(ios::left);
			cout << newAddress;
			cout.unsetf(ios::left);
			cout << "|" << endl;

			strCpy(address, newAddress);
		}
	}

	// display to screen the year, license plate, and address
	ostream& MotorVehicle::write(ostream& os) const {
		 os << "| " << year << " | " << licensePlate << " | " << address << "";
		 return os;
	}

	// read from user input
	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		cin >> year;
		cout << "License plate: ";
		cin >> licensePlate;
		cout << "Current location: ";
		cin >> address;
		return cin;
	}

	// return the write function
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle) {
		return vehicle.write(os);
	}

	//return the read function
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle) {
		return vehicle.read(in);
	}

}