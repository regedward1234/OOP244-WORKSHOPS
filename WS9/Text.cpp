/***********************************************************************
// Version 1.0
// Description: Function Implementation for Text class
/// Name: Reginald Edward
// Email: redward7@myseneca.ca
// Student Number: 149047227
// Date: July 27, 2023
// Section: OOP244 NAA
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/27      Added function implementation for the functions
//Reginald         2023/07/30      Updated assignment operator to fix issue with code
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   // one argument constructor
   Text::Text(const char* filename) {
       // set filename and content to nullptr
       m_filename = nullptr;
       m_content = nullptr;

       // set filename to incoming argument if incoming argument not nullptr
       if (filename != nullptr) {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       }
   }

   // copy constructor
   Text::Text(const Text& otherText) {
       // set attributes to nullptr
       m_filename = nullptr;
       m_content = nullptr;
       
       // copy object in argument to class attributes if object not nullptr
       if (otherText.m_filename != nullptr) {
           m_filename = new char[strLen(otherText.m_filename) + 1];
           strCpy(m_filename, otherText.m_filename);
           m_content = new char[strLen(otherText.m_content) + 1];
           strCpy(m_content, otherText.m_content);
       }
   }

   // copy assignment operator
   Text& Text::operator =(const Text& otherText) {
       // check if the address are not the same for both objects
       if (this != &otherText) {
          
           delete[] m_filename;
           delete[] m_content;
            
           // copy filename
           if (otherText.m_filename != nullptr) {
               m_filename = new char[strLen(otherText.m_filename) + 1];
               strCpy(m_filename, otherText.m_filename);
           }

           else {
               m_filename = nullptr;
           }

           // copy content
           if (otherText.m_content != nullptr) {
               m_content = new char[strLen(otherText.m_content) + 1];
               strCpy(m_content, otherText.m_content);
           }

           else {
               m_content = nullptr;
           }
       }
       return *this;
   }

   // destructor to deallocate memory for filename and content
   Text::~Text() {
       delete[] m_filename;
       delete[] m_content;
   }

   // index operator to return the value of m_content
   char& Text::operator[](int index)const {
       return m_content[index];
   }

   // read file
   void Text::read() {
       // open file
       ifstream f(m_filename);
     
       // if file is valid
       if (f) {
           // dynamically set the memory of m_content equal to file length
           m_content = new char[getFileLength() + 1];

           int i = 0;
           char ch;
           // get each character of content
           while (f.get(ch)) {
               m_content[i] = ch;
               i++;
           }

           // use null terminator for end of file
           m_content[getFileLength()] = '\0';
       }
   }

   // display content to screen
   void Text::write(ostream& os)const {
       if (m_content != nullptr) {
           os << m_content;
       }
   }

   // helper function for text object to ostream
   ostream& operator<<(ostream& os, const Text& text) {
       text.write(os);
       return os;
   }
}