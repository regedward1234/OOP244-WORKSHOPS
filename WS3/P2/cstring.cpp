/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: May 31, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#include "cstring.h"
namespace sdds {

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
