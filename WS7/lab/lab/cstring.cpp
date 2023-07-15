/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// Name: Reginald Edward
// Email: redward7@myseneca.ca
// Student Number: 149047227
// Date: July 14, 2023
// Section: OOP244 NAA
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/14      Added string function from other workshop
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include <cstdio>
#include <iostream>
#include "cstring.h"

using namespace std;

namespace sdds {

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

	//Compare between two strings to see if they are the same
	int strCmp(const char* s1, const char* s2) {
		int i;
		//Use for loop to go through each character of the string until NULL terminator
		for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
		{
			//Break out of the loop when a character in one string does not match character in the other
			if (s1[i] != s2[i])
			{
				break;
			}
		}
		//Calculate difference between each string
		return s1[i] - s2[i];
	}

	//Compare between each string string until length is reached or NULL terminator is reached
	int strnCmp(const char* s1, const char* s2, int len) {
		int i;
		//Use for loop to go through each chaaracter in both strings until length is reached or NULL terminator is reached 
		for (i = 0; i < len && s1[i] != '\0' && s2[i] != '\0'; i++)
		{
			//Break out of the loop when a character in one string does not match character in the other
			if (s1[i] != s2[i])
			{
				break;
			}
		}
		//If i and length is the same and no difference between string 1 and string 2 return 0 for match 
		if (i == len)
		{
			return 0;
		}
		//Calculate difference between each string
		return s1[i] - s2[i];
	}

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


	//Attached source string at end of destination string
	void strCat(char* des, const char* src) {
		int i, j = 0;


		//Use for loop to get the i value equal to end of the destination string
		for (i = 0; des[i] != '\0'; i++) {
		}
		//Use while loop to attach each character of source string to destination starting from end of destination string
		while (src[j] != '\0')
		{
			des[i] = src[j];
			i++;
			j++;
		}
		des[i] = '\0';
	}
}