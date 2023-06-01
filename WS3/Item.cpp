/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: May 30, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
//#include "cstring.h"
#include "Item.h"

using namespace std;
namespace sdds {

	//Sets the itemName member Cstring variable to a the Cstring in the name argument up to 20 characters.
	void Item::setName(const char* name) {
		strncpy(m_itemName, name, 20);
	}

	//Sets the Item to a recognizable safe Empty State.
	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	/*Sets the m_itemName attribute to the Cstring pointed by the name argument
	using the setName method and sets the m_price and m_taxed attributes to the corresponding arguments.*/
	void Item::set(const char* name, double price, bool taxed) {
		if (price < 0 || name == nullptr) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	//Returns the m_price attribute
	double Item::price()const {
		return m_price;
	}

	//Returns the product of m_price and 0.13(tax rate defined in MACRO) or returns 0 if m_taxed is false
	double Item::tax()const {
		double tempPrice;
		if (m_taxed == false) {
			tempPrice = 0.0;
		}
		else {
			tempPrice = m_price * TAX_RATE;
		}
		return tempPrice;
	}


	//Returns true if the Item is not set to the empty state
	bool Item::isValid()const {
		bool tempBool;
		if (m_itemName == nullptr && m_price == 0.0) {
			tempBool = false;
		}
		else {
			tempBool = true;
		}
		return tempBool;
	}
		
	
	
	//Prints an item
	void Item::display()const {
		if (isValid()==true) {
			cout << "| ";
			cout.width(20);
			cout.fill('.');
			cout.setf(ios::left);
			cout << m_itemName;
			cout.unsetf(ios::left);
			cout << " | ";
			cout.width(7);
			cout.fill(' ');
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << m_price;	
			cout.unsetf(ios::fixed);
			cout << " | ";
			if (m_taxed) {
				cout << "Yes";
			}
			else {
				cout << "No ";
			}
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}