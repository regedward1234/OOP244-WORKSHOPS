/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: June 11, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

namespace sdds {
	class Mark {
		int mark;

		//Set to invalid state
		void setEmpty();

	public:
		
		//No argument constructor sets value to 0
		Mark();

		//One argument constructor that set the value of mark with the incoming argument that meets requirements
		Mark(int markNum);

		//Overloaded int operator that returns marks if valid or 0 if invalid
		operator int() const;

		//Overload bool operator to check if marks is valid, meets requirements
		operator bool() const;

		//Add argument to value of mark. If mark is invalid do nothing
		Mark& operator+=(int addMark);

		//Mark is set to incoming argument if mark is valid
		Mark& operator=(int num);

		//Set the mark to GPA double value using overloaded operator
		operator double() const;

		//Set the mark to Grade char value using overloaded operator
		operator char() const;
		
		//helper += operator that adds mark to an integer using the overloaded int operator
		friend int operator+=(int& value, const Mark& marks);
	};
}
#endif