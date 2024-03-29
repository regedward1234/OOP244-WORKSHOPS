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
//Reginald         2023/07/19      Create a Line class
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _SDDS_LINE_H_
#define _SDDS_LINE_H_
#include "LblShape.h"

namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:	
		// no argument constructor
		Line();
		// two argument constructor
		Line(const char* string, int lengthOfLine);
		// reads commma separated specs of the line from istream
		void getSpecs(std::istream& is);
		// overrides draw of baseclass and prints to screen
		void draw(std::ostream& os) const;
	};
}








#endif