/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/

#include "Utils.h"
#include <iostream>
namespace sdds {
	//Loops through each character in the string and adds 1 for every character in string to get length
	int strLen(const char* s) {
		int stringLen = 0;
		int i;

		//Use for loop to count through each character of string until NULL terminator is reached
		for (i = 0; s[i] != '\0'; i++) {
			stringLen += 1;
		}
		return stringLen;
	}

	//Copies what is in source address to destination address. Ends string with NULL terminator
	void strCpy(char* des, const char* src) {
		int i;
		//Use for loop to go through each character in the source and copy it to destination
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}
		//Use Null terminator to end the string or cause a memory issue
		des[i] = '\0';

	}

}