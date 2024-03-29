/***********************************************************************
// OOP244 Menu Module
// File	Menu.h
// Version: 1.0
// Date: July 4th 2023
// Author: Reginald Edward
// Description: To display menu on screen and keep track of user selection
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/04      Added prototypes for the code 
//Reginald         2023/07/14      Fixed the display function headers
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#define MAX_MENU_ITEMS 20
#include <iostream>

namespace sdds {
    // forward declare the class menu in the header file
	class Menu;

	class MenuItem {
	private: 
		char* menuItemContent; // Cstring of characters for the content of the menu
		friend Menu; // make MenuItem class only accessible by the Menu class
		MenuItem(const char* stringContent); // sets the content of the MenuItem to Cstring value
		MenuItem(const MenuItem& content) = delete; // delete copy constructor so MenuItem object cannot be copied
		MenuItem& operator=(const MenuItem& content) = delete; // delete copy assignment so MenuItem object cannot be copied
		~MenuItem();
		operator bool() const; // returns true if it is not empty
		operator const char* () const; // return the address of the contect Cstring
		void displaymenuItem(std::ostream& os) const; // display the menucontent
	};

	class Menu {
	private:
		MenuItem* menuTitle;
		MenuItem* menuItems[MAX_MENU_ITEMS];
		int itemCount;
	public:
		Menu(const Menu& title) = delete; // delete copy constructor so Menu object cannot be copied
		Menu& operator=(const Menu& content) = delete; // delete copy assignment so Menuobject cannot be copied
		Menu(); // no argument constructor 
		Menu(const char* title); // Argument constructor that passes a menu title
		~Menu(); // destructor to delete pointer
		void displayTitle(std:: ostream& os) const; // display title of the menu
		void displayMenu(std::ostream& os) const; // display entire menu on ostream
		unsigned int run(); // displays the menu and gets user selection
		unsigned int operator~(); // overloaded ~ to do what run function does 
		Menu& operator<<(const char* menuitemContent); // overloaded << to add MenuItem to the Menu
		operator int() const; // return number of MenuItems on the Menu
		operator unsigned int() const; // return number of MenuItems on the Menu
		operator bool() const; // return true if the Menu has one or more MenuItems
		const char* operator[](unsigned int passedIndex) const; // return the const char* cast of corresponding MenuItem in the array of MenuItem pointers
		
	};
	std::ostream& operator<<(std::ostream& os, const Menu& menu);
	









}
#endif