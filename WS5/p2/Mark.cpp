/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: June 11, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {

	//Set to empty state
	void Mark::setEmpty() {
		mark = -1;
	}

	//No argument constructor sets value to 0
	Mark::Mark() {
		mark = 0;
	}

	//One argument constructor that set the value of mark with the incoming argument that meets requirements
	Mark::Mark(int markNum) {
		setEmpty();

		if (markNum >= 0 && markNum <= 100) {
			mark = markNum;
		}
	}

	//Overload bool operator to check if marks is valid, meets requirements
	Mark:: operator bool() const {
		bool tempBool;

		if (mark >= 0 && mark <= 100) {
			tempBool = true;
		}
		else {
			tempBool = false;
		}
		return tempBool;
	}

	//Overloaded int operator that returns marks if valid or 0 if invalid
	Mark:: operator int() const {
		int tempMark;

		//Use overloaded bool operator that checks if marks is valid
		if (*this) {
			tempMark = mark;
		}
		else {
			tempMark = 0;
		}
		return tempMark;
	}

	//Add argument to value of mark. If mark is invalid do nothing
	Mark& Mark:: operator+=(int addMark) {

		//Using overloaded bool operator to check if mark is valid and add argument to mark
		if (*this) {
			mark += addMark;
		}
		return *this;
	}

	//Mark is set to incoming argument if mark is valid
	Mark& Mark:: operator=(int num) {
		mark = num;

		//Using overloaded bool operator to check if mark is invalid
		if (!*this)
		{
			setEmpty();
		}
		return *this;
	}

	//Set the mark to GPA double value using overloaded operator
	Mark:: operator double() const {

		//Initializing the temp variable
		double tempdouble = -1.0;

		//Use overloaded bool operator to set value to 0 if mark is invalid 
		if (!*this) {
			tempdouble = 0.0;
		}

		//Use overloaded bool operator to set value to specific GPA value if mark is valid
		if (*this) {

			if (mark < 50) {
				tempdouble = 0.0;
			}

			if (mark >= 50 && mark < 60) {
				tempdouble = 1.0;
			}

			if (mark >= 60 && mark < 70) {
				tempdouble = 2.0;
			}

			if (mark >= 70 && mark < 80) {
				tempdouble = 3.0;
			}

			if (mark >= 80 && mark <= 100) {
				tempdouble = 4.0;
			}
		}
		return tempdouble;
	}

	//Set the mark to Grade char value using overloaded operators
	Mark:: operator char() const {

		//Initiazling char to null terminator
		char tempChar = '\0';

		//Use overloaded bool operator to set grade to 'X' if mark is invalid 
		if (!*this) {
			tempChar = 'X';
		}

		//Use overloaded bool operator to set grade to specific grade value if mark is valid 
		if (*this) {

			if (mark < 50) {
				tempChar = 'F';
			}

			else if (mark >= 50 && mark < 60) {
				tempChar = 'D';
			}

			else if (mark >= 60 && mark < 70) {
				tempChar = 'C';
			}

			else if (mark >= 70 && mark < 80) {
				tempChar = 'B';
			}

			else {
				tempChar = 'A';
			}
		}
		return tempChar;
	}

	//helper += operator that adds mark to an integer using the overloaded int operator
	int operator+=(int& value, const Mark& marks) {

		if (marks.mark >= 0 && marks.mark <= 100) {
			value += (int)marks;
		}
		return value;
	}
}