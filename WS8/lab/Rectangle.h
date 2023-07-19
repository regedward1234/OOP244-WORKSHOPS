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
//Reginald         2023/07/19      Create a Rectangle class
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _SDDS_RECTANGLE_H_
#define _SDDS_RECTANGLE_H_
#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	public:
		// no argument constructor
		Rectangle();
		// three argument constructor
		Rectangle(const char* cString, int width, int height);
		// reads comma separated specs of the rectangle from istream
		void getSpecs(std::istream& is);
		// draws rectangle
		void draw(std::ostream& os) const;
	};
}









#endif
