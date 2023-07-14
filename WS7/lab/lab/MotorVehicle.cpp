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

	void MotorVehicle::moveTo(const char* address) {

	}
}