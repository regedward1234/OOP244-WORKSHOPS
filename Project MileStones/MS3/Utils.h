/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version: 2.0
// Date: July 14th 2023
// Author: Reginald Edward
// Description: To help in the main functions
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Reginald        2023/07/04      Added the strLen and strCpy to use in modules
// Reginald        2023/07/25      Added the strStr and strnCpy function prototypes
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	int strLen(const char* s);
	void strCpy(char* des, const char* src);
	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2);
	// Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len);
}
#endif // SDDS_UTILS_H__
