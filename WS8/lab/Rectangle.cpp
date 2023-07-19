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
//Reginald         2023/07/19       Implement the functions for Rectangle class
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include "Rectangle.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	// set width and height to 0 and invoke default constructor of base class
	Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}

	Rectangle::Rectangle(const char* cString, int width, int height) : LblShape(cString), m_width(width), m_height(height) {
		// check if height less than 3 and width less than length of label + 2, if so set rectangle to empty state
		if (m_height < 3 || m_width < strLen(label()) + 2) {
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(std::istream& is) {
		// call getSpecs function of base class
		LblShape::getSpecs(is);
		// read two comma separated values from istream
		char comma;
		is >> m_width >> comma >> m_height;
		//ignore rest of characters up to and including newline character
		is.ignore(1000, '\n');
	}

	void Rectangle::draw(std::ostream& os) const {
		// is rectangle not in empty state 
		if (m_width != 0 && m_height != 0) {
			// print first line
			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+" << endl;
			// print second line
			os << "|";
			os.width(m_width - 2);
			os.setf(ios::left);
			os << label();
			os.unsetf(ios::left);
			os << "|" << endl;
			// print m_height -3 lines 
			for (int i = 0; i < m_height - 3; i++) {
				os << "|";
				for (int i = 0; i < m_width - 2; i++) {
					os << " ";
				}
				os << "|" << endl;
			}
			// print last line
			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+";

		}
	}
}