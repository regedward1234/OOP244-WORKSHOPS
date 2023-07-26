/***********************************************************************
// OOP244 Publication Module
// File	Publication.h
// Version: 1.0
// Date: July 21 2023
// Author: Reginald Edward
// Description: Create Publication class
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Reginald        2023/07/21      Create Publication class 
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/
#ifndef _SDDS_Publication_H
#define _SDDS_Publication_H
#include <iostream>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds {
	class Publication: public Streamable {
		char* m_title;
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];
		int m_membership;
		int m_libRef;
		Date m_date;
		void setEmpty();
	public:
		// constructor to set the attributes to to default values
		Publication();
		// destructor to deallocate memory
		virtual ~Publication();
		// Sets the membership attribute to either zero or a five-digit integer.
		virtual void set(int member_id);
		// Sets the **libRef** attribute value
		void setRef(int value);
		// Sets the date to the current date of the system
		void resetDate();
		//Returns the character 'P' to identify this object as a "Publication object"
		virtual char type()const;
		//Returns true is the publication is checkout (membership is non-zero)
		bool onLoan()const;
		//Returns the date attribute
		Date checkoutDate()const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		bool operator==(const char* title)const;
		//Returns the title attribute
		operator const char* ()const;
		//Returns the libRef attirbute. 
		int getRef()const;
		// pure virtual that writes into an ostream object
		virtual std::ostream& write(std::ostream& os) const;
		// pure virtual that will read from an istream object
		virtual std::istream& read(std::istream& istr);
		// receives reference of an ios object and returns a bool
		virtual bool conIO(std::ios& ios) const;
		// returns true if object is in valid state
		virtual operator bool() const;
		// copy constructor
		Publication(const Publication& other);
		// copy assignment
		Publication& operator=(const Publication& other);
	};
}




#endif