/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: May 31, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_CalorieList_H_
#define SDDS_CalorieList_H_
#include "Food.h"
namespace sdds {
    class CalorieList {
        char m_title[37];
        Food* foodName;
        int noOfItems;
        int ItemsAdded;
        int totalCalories()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        //CalorieList();
       // ~CalorieList();
        void init(int noOfItems);
        bool add(const char* item_name, int calories, int when);
        void display()const;
        void deallocate();
    };
}
#endif 