/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: May 25, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {
    
    int numberOfInputs;
    PostalPop* postalPop;
    

    void sort() {
        int i, j;
        PostalPop temp;
        for (i = numberOfInputs - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (postalPop[j].population > postalPop[j + 1].population) {
                    temp = postalPop[j];
                    postalPop[j] = postalPop[j + 1];
                    postalPop[j + 1] = temp;
                }
            }
        }
    }
    bool load(PostalPop& postalPops) {
        int postalCodeLength;
        bool ok = false;
        char postal[128];

      
       if (!read(postal)) {
            return ok;
       }

       if (!read(postalPops.population)) {
            return ok;
       }        

                 
            postalCodeLength = strLen(postal);
            postalPops.postalCode = new char[postalCodeLength + 1];


            strCpy(postalPops.postalCode, postal);

            ok = true;

            return ok;

        
    }
    
    
    bool load(const char* filename) {
        bool ok = false;
        int i = 0;
        if (openFile(filename)) {
          
            numberOfInputs = noOfRecords();

            postalPop = new PostalPop[numberOfInputs];


          
            for (i = 0; i < numberOfInputs; i++) {
                load(postalPop[i]);
            }


            if (i != numberOfInputs) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
           
            ok = true;
        
            closeFile();
        }
        else {
            cout << "Could not open data file: " << filename << endl;
        }
        return ok;
    }


    void display(const PostalPop& postalPop) {
        cout << postalPop.postalCode << ":  " << postalPop.population << endl;

    }

    void display() {
        int total = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < numberOfInputs; i++) {
            cout << i + 1 << "- ";
            display(postalPop[i]);
            total += postalPop[i].population;
        }
      
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << total << endl;
    }

    void deallocateMemory() {
        int i;
        for (i = 0; i < numberOfInputs; i++) {
            delete[] postalPop[i].postalCode;
        }

        delete[] postalPop;
        postalPop = nullptr;
    }



}


