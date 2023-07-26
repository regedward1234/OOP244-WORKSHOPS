/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version: 2.0
// Date: July 14th 2023
// Author: Reginald Edward
// Description: To help in the main functions
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/04      Added the prototypes for strLen and strCpy
// Reginald        2023/07/25      Added the strStr and strnCpy function implementation
///////////////////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-------------------------------------------------------------------------------
******************************************************************************/

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

	//Find the second string str2 in the first string str1
	const char* strStr(const char* str1, const char* str2) {
		int i, j;
		//cout << str1 << endl; testing the strings coming in for debugging
		//cout << str2 << endl; testing the strings coming in for debugging

		//Use for loop to loop through string one until NULL terminator 
		for (i = 0; str1[i] != '\0'; i++) {

			//Within loop use another loop to loop through string 2 and compare string 2 to string 1 if values matches
			for (j = 0; str2[j] != '\0' && str2[j] == str1[i + j]; j++) {
			}
			//If string 2 reaches end of string return the address of string 1
			if (str2[j] == '\0') {
				return &str1[i];
			}
		}
		//If no match then return NULLPTR
		return nullptr;
	}

	//Copies what is in source address to destination address. If length is less than source characters, will end string with NULL terminator
	void strnCpy(char* des, const char* src, int len) {
		int i;
		//Use for loop to go through each character in the source while less than length or not the NULL terminator and copy it to destination
		for (i = 0; i < len && src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		//If i is less than the length provided in parameter put NULL terminator to end the string
		if (i < len)
		{
			des[i] = '\0';
		}
	}

}