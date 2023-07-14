/***********************************************************************
// OOP244 Menu Module
// File	Menu.cpp
// Version: 1.0
// Date: July 4th 2023
// Author: Reginald Edward
// Description: To display menu on screen and keep track of user selection
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/04       Added intitial code based on project notes
//Reginald         2023/07/14       Added rest of the code Fixed each function so that it works
//Reginald         2023/07/14       Fixed the display function and the delete memory
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Utils.h"

using namespace std;
#include "Menu.h"
namespace sdds {

	MenuItem::MenuItem(const char* stringContent) {

		if (stringContent != nullptr) {
			// dyanmically set menuItemContent
			menuItemContent = new char[strLen(stringContent) + 1];
			strCpy(menuItemContent, stringContent);
		}
		else {
			menuItemContent = nullptr;
		}
	}

	MenuItem::~MenuItem() {
		// deallocate memeory for menuItemContent
		delete menuItemContent;
	}

	MenuItem::operator bool() const {
		bool temp;
		// if empty set to false
		if (menuItemContent == nullptr) {
			temp = false;
		}
		// if not empty set to true
		else {
			temp = true;
		}
		return temp;
	}

	MenuItem::operator const char* () const {
		// return menuItemContent
		return menuItemContent;
	}

	void MenuItem::displaymenuItem(std::ostream& os) const {
		// display content of menuItem
		if (menuItemContent != nullptr) {
			cout << menuItemContent;
		}

	}

	Menu::Menu() {
		// empty constructor set everything to empty state
		menuTitle = nullptr;
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			menuItems[i] = nullptr;
		}
		itemCount = 0;
	}

	Menu::Menu(const char* title) {
		// one argument constructor set incoming argument to menuTitle

		if (title != nullptr) {
			menuTitle = new MenuItem(title);

			for (int i = 0; i < MAX_MENU_ITEMS; i++) {
				menuItems[i] = nullptr;
			}

			itemCount = 0;
		}
	}

	Menu::~Menu() {
		// deallocate memory
		delete menuTitle;
		for (int i = 0; i < itemCount; i++) {
			delete menuItems[i];
		}
	}

	void Menu::displayTitle(std::ostream& os) const {
		if (menuTitle != nullptr) {
			menuTitle->MenuItem::displaymenuItem(os);
		}
	}

	void Menu::displayMenu(std::ostream& os) const {
		displayTitle(os);
		if (menuTitle != nullptr) {
			os << ":" << endl;
		}
		for (int i = 0; i < itemCount; i++) {
			os.width(2);
			os.setf(ios::right);
			os << i + 1 << "- ";
			os.unsetf(ios::right);
			//os << menuItems[i] << endl;
			menuItems[i]->displaymenuItem(os);
			os << endl;
		}

		os << " 0-" << " Exit" << endl << "> ";
	}

	unsigned int Menu::run() {
		// display menu and get user selection
		displayMenu(cout);

		unsigned int userSelection;

		// flag to get out of do while loop
		bool valid = false;

		// Use the understanding of c where scanf returns a value and use it with cin where 
		// if valid input should return a value
		do {
			if (!(cin >> userSelection) || userSelection < 0 || userSelection > itemCount) {
				cout << "Invalid Selection, try again: ";
				std::cin.clear();
				cin.ignore(100000, '\n');
			}
			else {
				valid = true;
			}

		} while (!valid);

		return userSelection;
	}

	unsigned int Menu::operator~() {
		// Do exactly what the run function does
		return run();
	}

	Menu& Menu::operator<<(const char* addMenuItemContent) {
		// check if next spot is available and not exceed max
		if (itemCount < MAX_MENU_ITEMS) {
			// dynamically create a MenuItem 
			menuItems[itemCount] = new MenuItem(addMenuItemContent);
			// increase MenuItem count by 1
			itemCount++;
		}
		return *this;
	}

	Menu::operator int() const {
		// return item count
		return itemCount;
	}
	Menu:: operator unsigned int() const {
		// return item count
		return itemCount;
	}

	Menu::operator bool() const {
		bool temp;
		// return true if menu has one more menuitems otherwise return false
		if (itemCount > 0) {
			temp = true;
		}
		else {
			temp = false;
		}
		return temp;
	}

	std::ostream& operator<<(std::ostream& os, const Menu& menu) {
		// Display the title of the menu
		menu.displayTitle(cout);
		return os;
	}

	const char* Menu::operator[](unsigned int index) const {
		// if index passes the number of MenuItem loop back to beginning using modulus.
		return menuItems[index % itemCount]->menuItemContent;
	}





}


