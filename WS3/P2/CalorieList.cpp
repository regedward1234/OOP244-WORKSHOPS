/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: May 31, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CalorieList.h"

using namespace std;
namespace sdds {

	//Set attributes to an empty state
	void CalorieList::setEmpty() {
		foodName = nullptr;
		noOfItems = 0;
		ItemsAdded = 0;

	}

	//Set to empty state if not valid. Other wise set noOfItems to size and allocate memory for dynamic array
	void CalorieList::init(int size) {
		if (size <= 0) {
			setEmpty();
		}
		else {
			foodName = new Food[size];
			noOfItems = size;
			ItemsAdded = 0;
		}
	}

	/*If the number of added Items (ItemsAdded) is less than the length of the noOfItems array,
	this function will set the next available subject to the incoming argument values.Then it
	will add one to the ItemsAdded and return true */
	bool CalorieList::add(const char* item_name, int calories, int when) {
		bool tempBool;

		if (ItemsAdded < noOfItems) {
			foodName[ItemsAdded].set(item_name, calories, when);
			ItemsAdded++;
			tempBool = true;
		}
		else {
			tempBool = false;
		}
		return tempBool;
	}

	//Returns true if foodName is not null and all the Items in the m_items array are valid.
	bool CalorieList::isValid()const {
		int i;
		if (foodName != nullptr) {
			for (i = 0; i < noOfItems; i++) {
				if (!foodName[i].isValid()) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	//Adds all the calories of the food 
	int CalorieList::totalCalories()const {
		int i;
		int totalCalories = 0;

		for (i = 0; i < ItemsAdded; i++) {
			totalCalories += foodName[i].calorie();
		}
		return totalCalories;
	}

	//Display a specific title if the valid function returns true or false
	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (CalorieList::isValid() == true) {
			cout << "| ";
			cout.width(48);
			cout.setf(ios::left);
			cout << " Daily Calorie Consumption                        ";
			cout.unsetf(ios::left);
			cout << " |"<< endl;
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}

		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;

	}


	//If valid function returns true then should return total calories if not should output same Invalid error as title
	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;

		if (CalorieList::isValid() == true) {
			cout << "|    Total Calories for today:   ";
			cout.width(6);
			cout.fill(' ');
			cout.setf(ios::fixed);
			cout << totalCalories();
			cout.unsetf(ios::fixed);
			cout << " |            |" << endl;

		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}

		cout << "+----------------------------------------------------+" << endl;
	}
	
	//Display title, items, and footer in that order
	void CalorieList::display()const {
		int i;
		Title();
		for (i = 0; i < noOfItems; i++) {
			foodName[i].display();
		}

		footer();
	}

	//deallocate the dynamic memory
	void CalorieList::deallocate() {
		delete[] foodName;
		foodName = nullptr;
	}
}
