// Final Project Milestone 3
// Publication Module
// File	Publication.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Reginald           2023/07/21          Added function implementations for Publications
// Reginald           2023/07/21          Fixed the read and write functions
// Reginald           2023/07/26          Added fail state to input string after research on stackoverflow
//---------------------------------------------------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//----------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "Publication.h"
#include "Lib.h"

using namespace std;
namespace sdds {

	// function to set attributes to default
	void Publication::setEmpty() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
	}
	// setting attributes to default values
	Publication::Publication() {
		setEmpty();
	}

	// set destructor for dynamically allocated attribute 
	Publication::~Publication() {
		delete[] m_title;
	}

	// set m_membershop to incoming argument
	void Publication::set(int member_id) {
		m_membership = member_id;
	}

	// set m_libRef to incoming argument
	void Publication::setRef(int value) {
		m_libRef = value;
	}

	// access date constructor to set to today date
	void Publication::resetDate() {
		m_date = Date();
	}

	// return charatcer P
	char Publication::type()const {
		return 'P';
	}

	// return true if publication is checked out
	bool Publication::onLoan()const {
		bool temp;

		if (m_membership != 0) {
			temp = true;
		}
		else {
			temp = false;
		}

		return temp;
	}

	// return the date attribute
	Date Publication::checkoutDate()const {
		return m_date;
	}

	// return true if argument title appears anywhere in title of the publication
	bool Publication::operator==(const char* title)const {
		bool temp;
		if (strStr(m_title, title) != nullptr) {
			temp = true;
		}
		else {
			temp = false;
		}

		return temp;
	}

	// return title attribute
	Publication::operator const char* ()const {
		return m_title;
	}

	// return libRef attribute
	int Publication::getRef() const {
		return m_libRef;
	}

	// display to screen 
	ostream& Publication::write(ostream& os) const {
		// check if conIO returns true
		if (conIO(os) == true) {
			os << "| " << m_shelfId << " | ";
			
			// left justify padded with dots for title 
			os.setf(ios::left);
			os.width(30);
			os.fill('.');
			os << m_title;
			os.unsetf(ios::left);
			os << " | ";

			// check if membership is 0 and if so print N/A
			if (m_membership != 0) {
				os << m_membership;
			}
			else {
				os << " N/A ";
			}
			os << " | " << m_date << " |";
		}
		else {
			os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t";
			os << m_title << "\t" << m_membership << "\t" << m_date;
		}
		return os;
	}

	// read from document
	istream& Publication::read(std::istream& istr) {
		// clear all the attributes 
		setEmpty();
		// free the memory
		delete[] m_title;
		
		// create local variables
		char tempTitle[256] = { '\0' };
		char tempShelfId[SDDS_SHELF_ID_LEN + 1];
		int tempMembership = 0;
		int tempLibRef = 0;
		Date tempDate;

		// check if conIO returns true
		if (conIO(istr) == true) {
			cout << "Shelf No: ";
			// get line for shelfId up to length of Id + 1 for null terminator
			istr.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1);

			// check if length of id is exactly 4 if not then set istr to fail state
			if (strLen(tempShelfId) != SDDS_SHELF_ID_LEN) {
				// use setstate function on input stream to set it to fail state
				istr.setstate(ios::failbit);
			}

			// get title using getline function to read up to 255 character or until it reaches new line 
			cout << "Title: ";
			istr.getline(tempTitle, 255);

			// get date
			cout << "Date: ";
			istr >> tempDate;
		}
		else {
			// get libRef and store in local variable and ignore new tab
			istr >> tempLibRef;
			istr.ignore();

			// get shelfId up to new tab and ignore the new tab 
			istr.get(tempShelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.ignore();

			// get title up to new tab or when 255 characters reached
			istr.getline(tempTitle, 255, '\t');

			// get membership and store in local variable and ignore new tab
			istr >> tempMembership;
			istr.ignore();
			
			// get date 
			istr >> tempDate;
		}

		// if date is invalid state then set istr to a fail state
		if (tempDate == false) {
			// use setstate function on input stream to set it to fail state
			istr.setstate(ios::failbit);
		}

		// if istr is in valid state using bool operator then assign the local variables to attributes
		if (istr) {
			m_title = new char[strLen(tempTitle) + 1];
			strCpy(m_title, tempTitle);
			m_title[strLen(tempTitle)] = '\0';
			m_libRef = tempLibRef;
			m_membership = tempMembership;
			strCpy(m_shelfId, tempShelfId);
			m_date = tempDate;
		}

		return istr;
	}

	// returns true if the address of the io object is the same as the address of cin or cout object
	bool Publication::conIO(ios& ios) const {
		bool temp;
		if (&ios == &cin || &ios == &cout) {
			temp = true;
		}
		else {
			temp = false;
		}
		return temp;
	}

	// returns true if object is in a valid state
	Publication::operator bool() const {
		bool temp;
		if (m_title != nullptr && m_shelfId[0] != '\0') {
			temp = true;
		}
		else {
			temp = false;
		}
		return temp;
	}

	// copy constructor 
	Publication::Publication(const Publication& other) {
		// deep copy of the attributes
		m_libRef = other.m_libRef;
		m_membership = other.m_membership;
		m_date = other.m_date;
		m_shelfId[SDDS_SHELF_ID_LEN] = '\0';
		strnCpy(m_shelfId, other.m_shelfId, SDDS_SHELF_ID_LEN);

		// deep copy the title attribute
		if (other.m_title != nullptr) {
			m_title = new char[strLen(other.m_title) + 1];
			strCpy(m_title, other.m_title);
		}
		else {
			m_title = nullptr;
		}
	}

	// copy assignment operator
	Publication& Publication::operator=(const Publication& other) {
		if (this != &other) {
			// deep copy of the attributes
			m_libRef = other.m_libRef;
			m_membership = other.m_membership;
			m_date = other.m_date;
			m_shelfId[SDDS_SHELF_ID_LEN] = '\0';
			strnCpy(m_shelfId, other.m_shelfId, SDDS_SHELF_ID_LEN);

			// delete the existing title and deep copy the new one
			delete[] m_title;
			if (other.m_title != nullptr) {
				m_title = new char[strLen(other.m_title) + 1];
				strCpy(m_title, other.m_title);
			}
			else {
				m_title = nullptr;
			}

		}
		return *this;
	}
}