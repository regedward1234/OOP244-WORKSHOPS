/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/14      Implement the functions 
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
	MotorVehicle::MotorVehicle(char* license, int year) {
		if (license != nullptr) {
			year = year;
			strnCpy(licensePlate, license, 8);
			strCpy(address, "Factory");
		}
	}

	void MotorVehicle::moveTo(const char* newAddress) {
		if (strCmp(address, newAddress) != 0) {
			cout << "|[";
			cout.width(8);
			cout.setf(ios::right);
			cout << licensePlate;
			cout.unsetf(ios::right);
			cout << "]| |[";
			cout.width(20);
			cout.setf(ios::right);
			cout << address;
			cout.unsetf(ios::right);
			cout << "] ---> [";
			cout.width(20);
			cout.setf(ios::right);
			cout << newAddress;
			cout.unsetf(ios::right);
			cout << "]|" << endl;

			strCpy(address, newAddress);
		}
	}
	ostream& MotorVehicle::write(ostream& os) const {
		 os << "| [" << year << "] | [" << licensePlate << "] | [" << address << "]" << endl;
		 return os;
	}

	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		cin >> year;
		cout << "License plate ";
		cin >> licensePlate;
		cout << "Current location: ";
		cin >> address;

		return cin;
	}

	std::ostream& operator<<(std::ostream& os, MotorVehicle& vehicle) {
		return vehicle.write(os);
	}

	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle) {
		return vehicle.read(in);
	}

}