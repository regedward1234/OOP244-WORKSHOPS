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
//Reginald         2023/07/19      Implement the functions for Line class
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds {
	// set m_length to 0, and invoke default constructor of base class
	Line::Line():LblShape(), m_length(0) {}
	
	// passes Cstring to constructor of the base class and sets m_length to value of second argument
	Line::Line(const char* Cstring, int lengthOfLine) : LblShape(Cstring), m_length(lengthOfLine) {}

	void Line::getSpecs(std::istream& is) {
		// call the getSpecs function of base class
		LblShape::getSpecs(is);
		//read m_length from istream
		is >> m_length;
		// ignore rest of characters up to and including newline character
		is.ignore(1000, '\n');
	}

	void Line::draw(std::ostream& os) const {
		// if length greater than 0 and label not nullptr
		if (m_length > 0 && label() != nullptr) {
			// print label
			os << label() << endl;
			// print "=" up to length
			for (int i = 0; i < m_length; i++) {
				os << "=";
			}
		}
	}
	
}