/***********************************************************************
// OOP244 Menu Module
// File	Menu.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
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
			menuItemContent = new char[strLen(stringContent) + 1];
			strCpy(menuItemContent, stringContent);
		}
		else {
			menuItemContent = nullptr;
		}
	}

	MenuItem::~MenuItem() {
		delete[] menuItemContent;
	}

	MenuItem::operator bool() const {
		bool temp;

		if (menuItemContent == nullptr) {
			temp = false;
		}
		else {
			temp = true;
		}
	}

	MenuItem::operator const char* () const {
		return menuItemContent;
	}

	std::ostream& MenuItem::display()const {
		if (menuItemContent != nullptr) {
			cout << menuItemContent;
		}
	}

	Menu::Menu() {
		menuTitle = nullptr;
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			menuItems[i] = nullptr;
		}
		itemCount = 0;
	}

	Menu::Menu(const char* title) {
		menuTitle = new MenuItem(title);
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			menuItems[i] = nullptr;
		}
	}

	Menu::~Menu() {
		delete[] menuTitle;
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			delete menuItems[i];
		}
	}

	void Menu::displayTitle() {
		if (menuTitle != nullptr) {
			cout << menuTitle;
		}
	}

	



}
