/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: May 31, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_CSTRING_H 
#define SDDS_CSTRING_H
namespace sdds {
   
    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len);

}


#endif