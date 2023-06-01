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
#include "cstring.h"
#include "Bill.h"

using namespace std;
namespace sdds {

	//Sets the Bill object to an empty state by setting m_title to an Empty Cstring and m_items to nullptr
	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	//Returns true if m_title is not empty and m_items is not null and all the Items in the m_items array are valid.
	bool Bill::isValid()const {
		bool tempBool = true;
		int i, keepGoing = 1;

		if (m_title[0] != '\0' && m_items != nullptr) {
			for (i = 0; i < m_noOfItems && keepGoing; i++) {
				if (!m_items[i].isValid()) {
					tempBool = false;
					keepGoing = 0;

				}
			}
		}
		else {
			tempBool = false;
		}
		return tempBool;
	}



	//Adds all the taxes of the items using a loop and returns the sum.
	double Bill::totalTax()const {
		int i;
		double totalTax = 0.0;

		for (i = 0; i < m_itemsAdded; i++) {
			totalTax += m_items[i].tax();
		}
		return totalTax;
	}

	//Adds all the prices of the items using a loop and returns the sum;
	double Bill::totalPrice()const {
		int i;
		double totalPrice = 0.0;

		for (i = 0; i < m_noOfItems; i++) {
			totalPrice += m_items[i].price();
		}
		return totalPrice;
	}

	//Prints the title
	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		if (Bill::isValid() == true) {
			cout << "| ";
			cout.width(36);
			cout.setf(ios::left);
			cout << m_title;
			cout.unsetf(ios::left);
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}


	//Prints the footer
	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;

		if (isValid() == true) {
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax();
			cout.unsetf(ios::fixed);
			cout << " |" << endl;
			cout << "|              Total Price: ";
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalPrice();
			cout.unsetf(ios::fixed);
			cout << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax() + totalPrice();
			cout.unsetf(ios::fixed);
			cout << " |" << endl;

		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+--------------------------------------+" << endl;
	}



	//Set to empty state if not valid  or allocate memory
	void Bill::init(const char* title, int noOfItems) {
		int i;

		if (title == nullptr || noOfItems <= 0) {
			setEmpty();
		}
		else {
			strnCpy(m_title, title, 36);
			m_title[36] = '\0';
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			m_items = new Item[m_noOfItems];

			for (i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	/*If the number of added Items (m_itemsAdded) is less than the length of the m_items array,
	this function will set the next available subject to the incoming argument values. Then it
	will add one to the m_itemsAdded and return true*/
	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool tempBool;

		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			tempBool = true;
		}
		else {
			tempBool = false;
		}
		return tempBool;
	}




	//Display
	void Bill::display()const {
		int i;

		Title();

		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}

		footer();
	}


	//Deallocates the m_items arrays and sets the pointers to null
	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}

}	