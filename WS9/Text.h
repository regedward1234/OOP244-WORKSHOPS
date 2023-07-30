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
//Reginald         2023/07/27      Added function prototypes for rule of three and insertion overload
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content;
      int getFileLength()const;
   protected:
      char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      // copy constructor
      Text(const Text& otherText);
      // copy assignment operator
      Text& operator=(const Text& otherText);
      // destructor
      virtual ~Text();

      void read();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // !SDDS_PERSON_H__

