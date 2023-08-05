/***********************************************************************
// OOP244 Menu Module
// File	LibApp.cpp
// Version: 2.0
// Date: August 03 2023
// Author: Reginald Edward
//Student Number: 149047227
// Description: To demo the execution of the Seneca Library Application with printing messages
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/14      Added the preliminary code for the project
//Reginald         2023/08/03      updates the functions in MS5 updates and added new functions in MS5 additions
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LibApp.h"
#include <fstream>
#include "Book.h"
#include "Utils.h"
#include "PublicationSelector.h"

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

		// MS5 update
		// open file for reading
		ifstream infile(m_fileName);
		char type{};
		int i;
		// loop through each publication until max reached or ifstream reading failes
		for (i = 0; infile && i < SDDS_LIBRARY_CAPACITY; i++) {
			// get first character
			infile >> type;
			infile.ignore();
			if (infile) {
				if (type == 'P')
					m_PPA[i] = new Publication;
				else if (type == 'B')
					m_PPA[i] = new Book;
				if (m_PPA[i]) {
					infile >> *m_PPA[i];
					m_NOLP++;
				}
			}
		}
		// if number of publication read greater than 0
		if (m_NOLP > 0) {
			// set library reference number to reference number of the last publication read 
			m_LLRN = m_PPA[m_NOLP - 1]->getRef();
		}
	}

	void LibApp::save() {
		// prints line
		cout << "Saving Data" << endl;

		// MS5 update
		// open data file for overwriting
		ofstream outfile(m_fileName);

		// loop through element of PPA up to NOLP
		for (int i = 0; i < m_NOLP; i++) {
			// if libRef not equal to 0
			if (m_PPA[i]->getRef() != 0) {
				// insert all elements into ofstream object
				outfile << *m_PPA[i] << endl;
			}
		}
	}

	int LibApp::search(int searchType) {
		// get library reference number, set to -1 to abort
		int libraryReferenceNumber;

		// MS5 Additions
		// run the publication menu to get type of publication
		int selection = m_publicationMenu.run();
		cin.ignore(1000, '\n');

		// if selection equal to 0 abort and set libreference number to -1
		if (selection == 0) {
			cout << "Aborted!" << endl;
			libraryReferenceNumber = -1;
		}
		else {
			// get title of publication to search for up to 256 characters
			char publicationTitle[256];
			cout << "Publication Title: ";
			cin.getline(publicationTitle, 256);

			// Create a PublicationSelector object with a page size of 15, 15 is default
			PublicationSelector userSelection("Select one of the following found matches:");

			// Loop through all publications in PPA
			for (int i = 0; i < m_NOLP; i++) {
				// check if reference is not 0
				if (m_PPA[i]->getRef() != 0) {
					/* if type is equal to B or P based on user input of 1 or 2 using ternary operator
					&& if title contains the title user entered using overloaded == operator */
					if (m_PPA[i]->type() == (selection == 1 ? 'B' : 'P') && *m_PPA[i] == publicationTitle) {

						// if search type is 1 then do full search and check if title contains the user entered title 
						if (searchType == 1) {
							userSelection << m_PPA[i];
						}
						// if search type is 2 search only those on loan
						else if (searchType == 2) {
							if (m_PPA[i]->onLoan()) {
								userSelection << m_PPA[i];
							}
						}
						// if search type is 3 then search publications which are not on loan
						else if (searchType == 3) {
							if (!m_PPA[i]->onLoan()) {
								userSelection << m_PPA[i];
							}
						}
					}
				}
			}
			// if matches are found 
			if (userSelection == true) {
				// use sort from PublicationSelector 
				userSelection.sort();

				// get user library reference from user selection
				int removalSelection = userSelection.run();

				// if user selected a row number
				if (removalSelection != 0) {
					// get address of publication object selected by user using library reference 
					Publication* selectedPublication = getPub(removalSelection);
					// returns library reference
					libraryReferenceNumber = selectedPublication->getRef();
					// display to screen the chosen row number
					selectedPublication->write(cout) << endl;
				}
				else {
					// Abort and set libraryReferenceNumber to -1
					cout << "Aborted!" << endl << endl;
					libraryReferenceNumber = -1;
				}
			}
			else {
				// Display no matches found and set libraryReferenceNumber to -1
				cout << "No matches found!" << endl << endl;
				libraryReferenceNumber = -1;
			}
		}

		return libraryReferenceNumber;
	}

	// MS5 update
	void LibApp::returnPub() {
		cout << "Return publication to the library" << endl;

		// call search function, prints lines, change value of m_changed to true
		int libRef = search(2);

		// check of search is not in fail state
		if (libRef != -1) {
			// call confirm function to cconfirm returning publication
			if (confirm("Return Publication?") == true) {
				// get address of object
				Publication* returnedPublication = getPub(libRef);
				// use date constrcutor to get current date and subtract checkoutdate from it
				int lateDays = Date() - returnedPublication->checkoutDate();
				double penalty = 0.00;
				// if number of days late greater than 15 charge 50 cents for each day late after that
				if (lateDays > 15) {
					int daysLate = lateDays - 15;
					penalty = (daysLate) * 0.50;
					// display the amount in two decimal places
					cout << "Please pay $";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << penalty;
					cout.unsetf(ios::fixed);
					cout << " penalty for being " << daysLate << " days late!" << endl;
				}
				// set m_changed to true and set membership number to 0
				m_changed = true;
				returnedPublication->set(0);
				cout << "Publication returned" << endl << endl;

			}
		}
	}

	// MS5 update
	void LibApp::newPublication() {
		// check if number of publications is not more than the capacity if it is display error
		if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl << endl;
		}
		else {
			cout << "Adding new publication to the library" << endl;

			// run publication menu and get user input
			int typeSelection = m_publicationMenu.run();

			// set publication object to null ptr
			if (typeSelection == 1 || typeSelection == 2) {
				Publication* pub = nullptr;

				// if 1 then create new book object
				if (typeSelection == 1) {
					pub = new Book;
				}
				// if 2 then create new publication object
				else if (typeSelection == 2) {
					pub = new Publication;
				}
				cin.ignore(1000, '\n');

				// read instantiated object from cin object
				cin >> *pub;

				// if cin fails flush keyboard
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!" << endl << endl;
					// delete publication type
					delete pub;
				}

				// call confirm function to confirm adding publication
				else if (confirm("Add this publication to the library?")) {
					// add one to LLRN
					m_LLRN++;
					// set library reference number to value
					pub->setRef(m_LLRN);
					// Add the publication object's address to the end of the PPA and add one to the NOLP.
					m_PPA[m_NOLP++] = pub;
					m_changed = true;
					cout << "Publication added" << endl;
					cout << endl;

				}
				else {
					cout << "Failed to add publication!" << endl;
					delete pub;
				}
			}
			else {
				cout << "Aborted!" << endl << endl;
			}
		}
	}

	// MS5 update
	void LibApp::removePublication() {
		cout << "Removing publication from the library" << endl;

		// search all the publications using search 1
		int libraryRef = search(1);
		if (libraryRef != -1) {
			// if confirm function returns true then change m_changed to true and set library reference to 0 and print line
			if (confirm("Remove this publication from the library?") == true) {
				Publication* selectedPublication = getPub(libraryRef);
				selectedPublication->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl << endl;
			}
		}
	}

	// MS5 update
	void LibApp::checkOutPub() {
		cout << "Checkout publication from the library" << endl;

		// search in available publications only using search 3
		int libraryRef = search(3);
		if (libraryRef != -1) {
			// if confirm function true then change m_changed to true and print line
			if (confirm("Check out publication?") == true) {
				m_changed = true;
				// Get membership number
				int memberShipID;
				cout << "Enter Membership number: ";
				do {
					cin >> memberShipID;

					// If the input is not five digit number then continue getting user input until valid
					if (cin.fail() || memberShipID < 10000 || memberShipID > 99999) {
						cout << "Invalid membership number, try again: ";
						cin.clear();
						cin.ignore(1000, '\n');

					}
				} while (cin.fail() || memberShipID < 10000 || memberShipID > 99999);

				// get address of publication
				Publication* selectedPublication = getPub(libraryRef);
				// set membership id of that object to membership id enetered
				selectedPublication->set(memberShipID);

				cout << "Publication checked out" << endl << endl;
			}
		}
	}

	// MS5 update add new attributes to constructor and change from no argument constructor to one argument constructor
	// initalize mainMenu and exitMenu  and publicationMenu during construction using constructor initialization
	LibApp::LibApp(const char* fileName) : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_NOLP(0), m_LLRN(0), m_publicationMenu("Choose the type of publication:") {
		strnCpy(m_fileName, fileName, 255);
		m_fileName[strLen(fileName)] = '\0';

		// add the menu items using the overloaded operator <<
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		// add the exit menu items using the overloaded operator <<
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";

		// add the publication menu using the overloaded operator <<
		m_publicationMenu << "Book";
		m_publicationMenu << "Publication";

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

	// MS5 additions returns address of publication object that had library ref number matching lib ref argument
	Publication* LibApp::getPub(int libRef) {
		Publication* foundPublication = nullptr;
		for (int i = 0; i < m_NOLP; i++) {
			if (m_PPA[i]->getRef() == libRef) {
				foundPublication = m_PPA[i];
			}
		}
		return foundPublication;
	}

	// MS5 addition adding destructor
	LibApp::~LibApp() {

		// Delete dynamically allocated Publication objects
		for (int i = 0; i < m_NOLP; ++i) {
			delete m_PPA[i];
		}
	}
}
