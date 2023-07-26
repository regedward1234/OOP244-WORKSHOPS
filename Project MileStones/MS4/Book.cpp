// Final Project Milestone 3
// Book Module
// File	Streamable.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Reginald           2023/07/26          Added book implementations 
////////////////////////////////////////////////////////////////////////
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------------------------------
******************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"
#include "Book.h"
#include "Utils.h"
#include "Lib.h"

using namespace std;
namespace sdds {
	// constructor to create book empty be default
	Book::Book() {
		authorName = nullptr;
	}

	// copy constructor
	Book::Book(const Book& otherBook) {
		// copy incoming argument to attribute dynamically
		if (otherBook.authorName != nullptr) {
			authorName = new char[strLen(otherBook.authorName) + 1];
			strCpy(authorName, otherBook.authorName);
		}
		else {
			authorName = nullptr;
		}
	}

	// copy assignment operator
	Book& Book::operator =(const Book& otherBook) {
		if (this != &otherBook) {
			// delete the existing authorName and deep copy the new one
			delete[] authorName;
			if (otherBook.authorName != nullptr) {
				authorName = new char[strLen(otherBook.authorName) + 1];
				strCpy(authorName, otherBook.authorName);
			}
			else {
				authorName = nullptr;
			}

		}
		return *this;
	}
	
	// destructor to deallocate memory for authorName
	Book::~Book() {
		delete[] authorName;
	}

	// return a character B
	char Book::type()const {
		return 'B';
	}

	ostream& Book::write(ostream& os) const {
		// invoke write of base class
		Publication::write(os);

		// check if incoming argument is console IO object
		if (conIO(os) == true) {
			os << " ";
			// set width to max length defined in Lib.h
			os.width(SDDS_AUTHOR_WIDTH);
			os << authorName;
			os << " |";
		}
		else {
			os << '\t';
			os << authorName;
		}
		return os;
	}

	istream& Book::read(istream& istr) {
		char tempAuthorName[1000];
		// invoke the read of the base class
		Publication::read(istr);
		
		// free memory held for author's name
		delete[] authorName;

		// if incoming argument is console IO object
		if (conIO(istr) == true) {
			// skip the /n
			istr.ignore();
			cout << "Author: ";
			istr.getline(tempAuthorName, 1000);
		}
		else {
			// ignore the tab character
			istr.ignore();
			istr.getline(tempAuthorName, 1000);
		}

		// if istream not in a fail state dynamically hold the author's name in char pointer
		if (istr) {
			// dynamically allocate memory to size of temp string
			authorName = new char[strLen(tempAuthorName) + 1];
			// copy the tempAuthorName to attribute
			strCpy(authorName, tempAuthorName);
		}
		return istr;
	}
}