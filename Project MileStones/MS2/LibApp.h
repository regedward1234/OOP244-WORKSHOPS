/***********************************************************************
// OOP244 Menu Module
// File	LibApp.h
// Version: 1.0
// Date: July 14th 2023
// Author: Reginald Edward
// Description: To demo the execution of the Seneca Library Application with printing messages
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/14      Added the prototypes for all the functions
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds {
   class LibApp {
	   bool m_changed;
	   Menu m_mainMenu;
	   Menu m_exitMenu;
	   bool confirm(const char* message); //instantiate a Menu and initialize it with message argument
       void load(); // prints: "Loading Data"<NEWLINE>
       void save(); // prints: "Saving Data"<NEWLINE>
       void search(); // prints: "Searching for publication"<NEWLINE>
       void returnPub(); //  Calls the search() method.
       void newPublication(); // adds new publication to library
       void removePublication(); // removes publication from library
       void checkOutPub(); // calls search then confirm methods
   public:
       LibApp();
       void run();
                         
   };
}
#endif // !SDDS_LIBAPP_H



