/***********************************************************************
// OOP244 STREAMABLE Module
// File	Lib.h
// Version: 1.0
// Date: July 21 2023
// Author: Reginald Edward
// Description: Create Streamable interface
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Reginald        2023/07/21      Create Streamable interface
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/
#ifndef _SDDS_STREAMABLE_H
#define _SDDS_STREAMABLE_H
#include <iostream>

namespace sdds {
	class Streamable {
	public:
		// pure virtual that writes into an ostream object
		virtual std::ostream& write(std::ostream& os) const = 0;
		// pure virtual that will read from an istream object
		virtual std::istream& read(std::istream& is) = 0;
		// receives reference of an ios object and returns a bool
		virtual bool conIO(const std::ios& ios) const = 0;
		// returns true if streamable object is in valid state
		virtual operator bool() const = 0;
		// destructor 
		virtual ~Streamable();
	};
	// Overload the insertion operator so a object of type Streamable can be written on an ostream object
	std::ostream& operator<<(std::ostream&os, const Streamable& streamObject);
	// Overload the extraction operator so an object of type Streamable can be read from an istream objec
	std::istream& operator>>(std::istream& is, Streamable& streamObject);
}



#endif
