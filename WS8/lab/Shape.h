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
//Reginald         2023/07/19      Create a Shape class
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _SDDS_SHAPE_H_
#define _SDDS_SHAPE_H_
#include <iostream>
namespace sdds {
	class Shape {
	public:
		// pure virtual that receives a reference to ostream as argument
		virtual void draw(std::ostream& os) const = 0;
		// pure virtual that receives a reference to istream as argument
		virtual void getSpecs(std::istream& is) = 0;
		// virtual destructor initalized to empty
		virtual ~Shape() {};
};
	// overloading the insertion operator for writing a shape
	std::ostream& operator<<(std::ostream& os, const Shape& shape);
	// overloading the extraction operator for reading a shape
	std::istream& operator>>(std::istream& is, Shape& shape);
}
#endif
