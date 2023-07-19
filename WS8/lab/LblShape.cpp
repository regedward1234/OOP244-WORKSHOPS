/***********************************************************************
// Version 1.0
// Description:
/// Name: Reginald Edward
// Email: redward7@myseneca.ca
// Student Number: 149047227
// Date: July 19, 2023
// Section: OOP244 NAA
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/19      Implement the functions for LblShape class
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LblShape.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	// returns m_label
	const char* LblShape::label()const {
		return m_label;
	}

	// empty constructor to set attribute to nullptr
	LblShape::LblShape() : m_label(nullptr) {}
    
	// one argument constructor that sets incoming argument to attribute
	LblShape::LblShape(const char* labelString) : m_label(nullptr){
		if (labelString != nullptr) {
			m_label = new char[strLen(labelString) + 1];
			strCpy(m_label, labelString);
		}
	}

	// destructor deletes memory 
	LblShape::~LblShape() {
		delete[] m_label;
	}
	
	// read line until "," reached and allocate memory to hold it
	void LblShape::getSpecs(std::istream& is) {
		char tempString[1000];
		is.getline(tempString,1000, ',');

		delete[] m_label;

		if (tempString != nullptr) {
			m_label = new char[strLen(tempString) + 1];
			strCpy(m_label, tempString);
		}
	}
}