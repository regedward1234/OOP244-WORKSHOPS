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
//Reginald         2023/07/19       Implement the functions for Shape class
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds {
	// overloading the insertion operator for writing a shape
	ostream& operator<<(ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}
	// overloading the extraction operator for reading a shape
	istream& operator>>(istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	}
}