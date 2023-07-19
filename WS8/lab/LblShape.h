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
//Reginald         2023/07/19      Create a LblShape class 
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _SDDS_LBLSHAPE_H_
#define _SDDS_LBLSHAPE_H_
#include <iostream>
#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
		char* m_label = nullptr;
	protected:
		// query to get label
		const char* label()const;
	public:
		// no argument constructor
		LblShape();
		// one argument constructor
		LblShape(const char* labelString);
		// destructor
		virtual ~LblShape();
		// delete copy constructor and copy assignment operator
		LblShape(LblShape& otherShape) = delete;
		LblShape& operator=(LblShape& otherShape) = delete;
		// override the getSpecs pure virtual
		void getSpecs(std::istream& is);
};
}








#endif
