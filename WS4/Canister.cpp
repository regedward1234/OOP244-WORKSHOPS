/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: June 04, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

	//Global definition of PI
	double const PI = 3.14159265;

	//Set to default values
	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	//Returns true if content valume is less than 0.00001
	bool Canister::isEmpty()const {
		bool tempBool;
		if (m_contentVolume < 0.00001) {
			tempBool = true;
		}
		else {
			tempBool = false;
		}
		return tempBool;
	}

	//Compare content name of canister with one received in parameter
	bool Canister::hasSameContent(const Canister& c)const {
		bool tempBool;

		if (c.m_contentName != nullptr && m_contentName != nullptr && (strCmp(c.m_contentName, m_contentName) == 0)) {
			tempBool = true;
		}
		else {
			tempBool = false;
		}

		return tempBool;
	}

	//Set content name of the canister
	void Canister::setName(const char* Cstr) {
		int length;
		if (Cstr != nullptr && m_usable == true) {
			delete[] m_contentName;

			length = strLen(Cstr);
			m_contentName = new char[length + 1];

			strCpy(m_contentName, Cstr);
		}
	}

	//Create constructor to set values to empty state
	Canister::Canister() {
		setToDefault();
	}

	//Set attributes to default value and name to parameter name
	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}

	//Set the canister information if it meets requirements if not set it to unusable
	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();
		if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			setName(contentName);
		}
		else {
			m_usable = false;
		}
	}

	//Destructor to deallocate memory for content name
	Canister::~Canister() {
		delete[] m_contentName;
	}

	//Clear unusable canister back to empty state
	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	//Returns the capacity 
	double Canister::capacity()const {
		double capacity;

		capacity = PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);

		return capacity;
	}

	//Returns content volume
	double Canister::volume()const {
		return m_contentVolume;
	}

	//Set the content name and returns the reference of the current object
	Canister& Canister::setContent(const char* contentName) {
		if (contentName == nullptr) {
			m_usable = false;
		}
		else if (isEmpty() == true) {
			setName(contentName);
		}
		else if (hasSameContent(contentName) == false) {
			m_usable = false;
		}

		return *this;
	}

	//Add quantity argument to content volume if the sum if less than equal to capacity
	Canister& Canister::pour(double quanitity) {
		if (m_usable == true && quanitity > 0 && (quanitity + volume()) <= capacity()) {
			m_contentVolume += quanitity;
		}
		else {
			m_usable = false;
		}

		return *this;
	}


	//Pour the content of the Canister argument into the current canister
	Canister& Canister::pour(Canister& C) {
		setContent(C.m_contentName);
		if (C.volume() > capacity() - volume()) {
			C.m_contentVolume -= (capacity() - volume());
			m_contentVolume = capacity();
		}
		else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}

		return *this;
	}

	//Prints the canister
	std::ostream& Canister::display()const {
		cout.precision(1);
		cout.setf(ios::fixed);
		cout.width(7);
		cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";

		if (m_usable == false) {
			cout << " of Unusable content, discard!";
		}
		else {
			if (m_contentName != nullptr) {
				cout << " of ";
				cout.width(7);
				cout << m_contentVolume;
				cout << "cc   " << m_contentName;
			}
		}
		cout.unsetf(ios::fixed);
		return std::cout;
	}
}