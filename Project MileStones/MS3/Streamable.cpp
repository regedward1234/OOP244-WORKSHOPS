// Final Project Milestone 3
// STREAMABLE Module
// File	Streamable.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Reginald           2023/07/21          Added function implementations 
//---------------------------------------------------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//----------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"

using namespace std;
namespace sdds {
	ostream& operator<<(ostream& os, const Streamable& streamObject) {
		// if streamable object is in valid state write on ostream
		if (streamObject == true) {
			streamObject.write(os);
		}
		return os;
	}
	istream& operator>>(istream& is, Streamable& streamObject) {
		// object of type streamable can be read from an istream object
		streamObject.read(is);
		return is;
	}
}