/***********************************************************************
// Version 1.0
// Description:
/// Name: Reginald Edward
// Email: redward7@myseneca.ca
// Student Number: 149047227
// Date: July 27, 2023
// Section: OOP244 NAA
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/27      Create class for HtmlText
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include <iostream>
#include "Text.h"

namespace sdds {
   class HtmlText :  public Text {
      char* m_title;
   public:
       // constructor to create object with with filename and title
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      // override write function
      virtual void write(std::ostream& os)const;
      // copy constructor
      HtmlText(const HtmlText& other);
      // copy assignment operator
      HtmlText& operator=(const HtmlText& other);
      // destructor to deallocate memory to title
      virtual ~HtmlText();


   };
}
#endif // !SDDS_HTMLTEXT_H__
