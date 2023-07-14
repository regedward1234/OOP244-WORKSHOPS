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
		cout << "Publication returned" << endl << endl;
		m_changed = true;
	}

	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		
		// if confirm function returns true then change m_changed to true and print line
		if (confirm("Add this publication to library?") == true) {
			m_changed = true;
			cout << "Publication added";
		}
		cout << endl;
	}

	void LibApp::removePublication() {
		cout << "Remove publication from library" << endl;
		search();

		// if confirm function returns true then change m_changed to true and print line
		if (confirm("Remove this publication from the library?") == true) {
			m_changed = true;
			cout << "Publication removed" << endl << endl;
		}
	}

	void LibApp::checkOutPub() {
		search();

		// if confirm function true then change m_changed to true and print line
		if (confirm("Check out publication?") == true) {
			m_changed = true;
			cout << "Publication checked out" << endl << endl;
		}
	}

	// initalize mainMenu and exitMenu during construction using constructor initialization
	LibApp::LibApp(): m_changed (false), m_mainMenu("Seneca Library Application"), m_exitMenu ("Changes have been made to the data, what would you like to do?") {
			
		// add the menu items using the overloaded operator <<
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		// add the exit menu items using the overloaded operator <<
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";

		// call the load method
		load();
	}

	void LibApp::run() {
		int userSelection;
		int UserSelectionForExit;
		bool terminateMessage = false;

		do {
			// display main menu
			userSelection = m_mainMenu.run();

			// based on userSelection calls corresponding private method
			if (userSelection == 1) {
				newPublication();
			}

			if (userSelection == 2) {
				removePublication();
			}

			if (userSelection == 3) {
				checkOutPub();
			}

			if (userSelection == 4) {
				returnPub();
			}

		} while (userSelection != 0);

		/* examine m_changed if it false then terminate program if true
		* call the exit menu using run and go to two other options of exiting
		*/
		if (m_changed == true) {
			UserSelectionForExit = m_exitMenu.run();

			// if user enters 1 in exit screen call save
			if (UserSelectionForExit == 1) {
				save();
				terminateMessage = true;

			}
			// if user enters 2 in exit screen call run function
			else if (UserSelectionForExit == 2) {
				cout << endl;
				run();
			}
			else {
				// if true then go back to main menu
				if (confirm("This will discard all the changes are you sure?") == false) {
					run();
				}
				else {
					terminateMessage = true;
				}
			}
		}
		else {
			terminateMessage = true;
		}

		if (terminateMessage == true) {
			// print exit message
			cout << endl;
			cout << "-------------------------------------------" << endl;
			cout << "Thanks for using Seneca Library Application" << endl;
		}
	}

	 
}
