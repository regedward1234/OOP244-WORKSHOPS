/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: May 23, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include "cstring.h"


namespace sdds {
   FILE* fptr;
   
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO: read functions go here
   bool read(char* empName) {
       bool success = fscanf(fptr,"%[^\n]\n", empName) == 1;
       
       return success;
   }
   
   bool read(int& empNumber) {
       bool success = fscanf(fptr,"%d,", &empNumber) == 1;
      return success;
   }
   
   bool read(double& empSalary) {
       bool success = fscanf(fptr, "%lf,", &empSalary) == 1;

      return success;
   }
   
}