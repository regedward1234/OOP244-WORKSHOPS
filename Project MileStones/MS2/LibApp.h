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
   public:
       LibApp();
       void newPublication(); // adds new publication to library
       void removePublication(); // removes publication from library
       void checkOutPub(); // calls search then confirm methods
       void run();
                         
   };
}
#endif // !SDDS_LIBAPP_H



