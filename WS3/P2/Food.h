/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: May 31, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
#define TAX_RATE 0.13
namespace sdds {
    class Food {
        char foodName[311];
        int calorieNumber;
        int consumptionTime;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calories, int consumptionTotal);
        void display()const;
        bool isValid()const;
        int calorie()const;
       
    };
}

#endif 