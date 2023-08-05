/***********************************************************************
// OOP244 Menu Module
// File	LibApp.h
// Version: 2.0
// Date: August 03 2023
//Student Number: 149047227
// Author: Reginald Edward
// Description: To demo the execution of the Seneca Library Application with printing messages
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/14      Added the prototypes for all the functions
//Reginald         2023/08/01      Add more attributes to LibApp class
//Reginald         2023/08/03      Added more functions under MS5 additions and updates under MS5 updates
/////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------
***********************************************************************/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Lib.h"
#include "Publication.h"

namespace sdds {
   class LibApp {
	   bool m_changed;
	   Menu m_mainMenu;
	   Menu m_exitMenu;
       
       // MS5 additions
       char m_fileName[256]; // array of 256 characters to hold publication data file name
       Publication* m_PPA[SDDS_LIBRARY_CAPACITY]; //array containing all the records of publication file
       int m_NOLP; // int to hold number of publications loaded into PPA
       int m_LLRN; // int to add the last library reference number read from file
       Menu m_publicationMenu; // get publication type Menu

       bool confirm(const char* message); //instantiate a Menu and initialize it with message argument
       
       // MS5 updates 
       void load(); // prints: "Loading Data"<NEWLINE>, read all publications
       void save(); // prints: "Saving Data"<NEWLINE>, insert all elements into ofstream except those with 0
       int search(int searchType); // prints: "Searching for publication"<NEWLINE>, search publications in 3 ways
       void returnPub(); //  Calls the search() method.
       void newPublication(); // adds new publication to library
       void removePublication(); // removes publication from library
       void checkOutPub(); // calls search then confirm methods
   public:
       // one argument constructor
       LibApp(const char* fileName);
       void run();

       // MS5 additions
       // return address of a Publication object that has library reference number matching argument
       Publication* getPub(int libRef);
       // destructor for dynamic memory for m_PPA
       virtual ~LibApp();
   };
}
#endif // !SDDS_LIBAPP_H



