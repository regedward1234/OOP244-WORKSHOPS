/***********************************************************************
// OOP244 Menu Module
// File	LibApp.cpp
// Version: 1.0
// Date: July 14th 2023
// Author: Reginald Edward
// Description: To demo the execution of the Seneca Library Application with printing messages
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/14
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LibApp.h"

using namespace std;
namespace sdds {

	bool LibApp::confirm(const char* message) {
		bool temp;

		// create an object of Menu and add yes to it using overloaded operator <<
		Menu menu(message);
		menu << "Yes";

		// run the menu and return true if run methods returns 1
		if (menu.run() == 1) {
			temp = true;
		}
		else {
			temp = false;
		}
		return temp;
	}

	void LibApp::load() {
		// prints line
		cout << "Loading Data" << endl;
	}

	void LibApp::save() {
		// prints line
		cout << "Saving Data" << endl;
	}

	void LibApp::search() {
		// prints line
		cout << "Searching for publication" << endl;
	}

	void LibApp::returnPub() {
		// call search function, prints lines, change value of m_changed to true
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}

	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		
		// if confirm function returns true then change m_changed to true and print line
		if (confirm("Add this publication to library?") == true) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}

	void LibApp::removePublication() {
		cout << "Remove publication from library" << endl;
		search();

		// if confirm function returns true then change m_changed to true and print line
		if (confirm("Remove this publication from the library?") == true) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}

	void LibApp::checkOutPub() {
		search();

		// if confirm function true then change m_changed to true and print line
		if (confirm("Check out publication?") == true) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}
}
