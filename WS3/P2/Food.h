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
namespace sdds {
    class Food {
        char foodName[31];
        int calorieNumber;
        int consumptionTime;
        
        //Set name to foodName using input from client code and ensuring it is null terminated
        void setName(const char* name);
    public:
        
        //Constructor for Food to set all the data members to 0
        Food();
        
        //Destructor for food 
        ~Food();

        //Set all the data members to empty state
        void setEmpty();

        //Set incoming parameters to each of the data members
        void set(const char* name, int calories, int consumptionTotal);

        //Display the table
        void display()const;

        //Check if incoming parameters are meet requirements
        bool isValid()const;

        //Calculate total calories of all the foods
        int calorie()const;
       
    };
}

#endif 