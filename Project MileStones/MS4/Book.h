/***********************************************************************
// OOP244 Book Module
// File	Book.h
// Version: 1.0
// Date: July 26 2023
// Author: Reginald Edward
// Description: Create Book class
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Reginald        2023/07/26      Create Book class
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/
#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H
#include <iostream>
#include "Publication.h"

namespace sdds {
	class Book : public Publication {
		char* authorName;
	public:
		// constructor for book
		Book();
		// copy constructor
		Book(const Book& otherBook);
		// copy assignment operator
		Book& operator =(const Book& otherBook);
		// destructor to deallocate memory
		virtual ~Book();
		// return character B
		virtual char type() const;
		// display to screen publication with author name
		virtual std::ostream& write(std::ostream& os) const;
		// read author name
		virtual std::istream& read(std::istream& istr);
		// invoke set of base class
		virtual void set(int member_id);
		//returns true if author name exists and not empty and base class returns true
		virtual operator bool() const;

	};
}
#endif