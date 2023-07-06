/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: July 03, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#include "cstring.h"
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