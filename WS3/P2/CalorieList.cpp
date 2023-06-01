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
#include <string.h>
//#include "cstring.h"
#include "CalorieList.h"

using namespace std;
namespace sdds {

	CalorieList::CalorieList() {
		foodName = nullptr;
		noOfItems = 0;

	}

	CalorieList::~CalorieList() {
		delete[] foodName;
	}

	void CalorieList::init(int size) {
		foodName = new Food[size];
		noOfItems = size;
		ItemsAdded = 0;
	}

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
	bool CalorieList::isValid()const {
		int i;
		if (foodName != nullptr) {
			for (int i = 0; i < ItemsAdded; i++) {
				if (!foodName[i].isValid()) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	int CalorieList::totalCalories()const {
		int i;
		int totalCalories = 0;

		for (i = 0; i < ItemsAdded; i++) {
			totalCalories += foodName[i].calorie();
		}
		return totalCalories;
	}


	void CalorieList::Title()const {
			cout << "+--------------------------------+------+------------+" << endl;
			if (CalorieList::isValid() == true) {
				cout << "| ";
				cout.width(48);
				cout.setf(ios::left);
				cout << " Daily Calorie Consumption                        ";
				cout.unsetf(ios::left);
				cout << " |" << endl;
			}
			else {
				cout << "| Invalid Calorie Consumption List                   |" << endl;
			}

			cout << "+--------------------------------+------+------------+" << endl;
			cout << "| Food Name                      | Cals | When       |" << endl;
			cout << "+--------------------------------+------+------------+" << endl;
		
	}

	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;

		if (CalorieList::isValid() == true) {
			cout << "|    Total Calories for today:     ";
			cout.width(4);
			cout.fill(' ');
			cout.setf(ios::fixed);
			cout << totalCalories();
			cout.unsetf(ios::fixed);
		    cout <<" |            |" << endl;

		}
		else {
			cout << "|    Invalid Calorie Consumption List                |" << endl;
		}

		cout << "+--------------------------------+------+------------+"  << endl;
	}
	void CalorieList::display()const {
		int i;
		Title();
		for (i = 0; i < ItemsAdded; i++) {
			foodName[i].display();
		}

		footer();
	}


	void CalorieList::deallocate() {
		delete[] foodName;
		foodName = nullptr;
	}
	}

