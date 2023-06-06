/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: June 04, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds {
	class Canister {
		char* m_contentName;
		double m_diameter; // in centimeters 
		double m_height;   // in centimeters
		double m_contentVolume;  // in CCs
		bool m_usable;

		//Set to default values
		void setToDefault();

		//Set content name of the canister
		void setName(const char* Cstr);

		//Returns true if content valume is less than 0.00001
		bool isEmpty()const;

		//Compare content name of canister with one received in parameter
		bool hasSameContent(const Canister& C)const;
	public:

		//Constructor to set values to empty state
		Canister();

		//Set attributes to default value and name to parameter name
		Canister(const char* contentName);

		//Set the canister information if it meets requirements if not set it to unusable
		Canister(double height, double diameter,
			const char* contentName = nullptr);

		//Destructor to deallocate memory for content name
		~Canister();

		//Set the content name and returns the reference of the current object
		Canister& setContent(const char* contentName);

		//Add quantity argument to content volume if the sum if less than equal to capacity
		Canister& pour(double quantity);

		//Pour the content of the Canister argument into the current canister
		Canister& pour(Canister&);

		//Returns content volume
		double volume()const;

		//Prints the canister
		std::ostream& display()const;

		//Returns the capacity 
		double capacity()const;

		//Clear unusable canister back to empty state
		void clear();
	};
}

#endif // !SDDS_BOX_H
