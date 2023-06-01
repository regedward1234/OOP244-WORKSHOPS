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
		Food* foodName;
		int noOfItems;
		int ItemsAdded;

		//Get total calories of all the food
		int totalCalories()const;

		//Display title
		void Title()const;

		//Display footer
		void footer()const;

		//Set the data members to empty state 
		void setEmpty();

		//Check if the arguements for each data member meet requirments
		bool isValid()const;
	
	public:

		//Get userInput for item numbers and set it to data member noOfItems
		void init(int noOfItems);

		//Add the items that meet requirments into array
		bool add(const char* item_name, int calories, int when);


		//Display the table 
		void display()const;

		//Deallocate the dynamic memory
		void deallocate();
	};
}
#endif 