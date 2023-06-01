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
#include "Food.h"

using namespace std;
namespace sdds {

	//Sets the itemName member Cstring variable to a the Cstring in the name argument up to 20 characters.
	void Food::setName(const char* name) {
		strncpy(foodName, name, 30);
		foodName[30] = '\0';
	}

	//Sets the Item to a recognizable safe Empty State.
	void Food::setEmpty() {
		calorieNumber = 0.0;
		foodName[0] = '\0';
	}

	/*Sets the m_itemName attribute to the Cstring pointed by the name argument
	using the setName method and sets the m_price and m_taxed attributes to the corresponding arguments.*/
	void Food::set(const char* name, int calories, int consumptionTimes) {
		if (calories <= 0 || calories > 3000 || name == nullptr || consumptionTimes < 1 || consumptionTimes > 4) {
			setEmpty();
		}
		else {
			setName(name);
			calorieNumber = calories;
			consumptionTime = consumptionTimes;
		}
	}

	int Food::calorie()const {
		return calorieNumber;
	}


	bool Food::isValid()const {
		bool tempBool;
		if (foodName[0] == '\0' || calorieNumber <= 0 || calorieNumber > 3000 || consumptionTime < 1 || consumptionTime > 4) {
			tempBool = false;
		}
		else {
			tempBool = true;
		}
		return tempBool;
	}

	void Food::display()const {
		if (isValid() == true) {
			cout << "| ";
			cout.width(30);
			cout.fill('.');
			cout.setf(ios::left);
			cout << foodName;
			cout.unsetf(ios::left);
			cout << " | ";
			cout.width(4);
			cout.fill(' ');
			cout.setf(ios::fixed);
			cout << calorieNumber;
			cout.unsetf(ios::fixed);
			cout << " | ";
			cout.width(10);
			cout.fill(' ');
			cout.setf(ios::left);

			switch (consumptionTime) {
			case 1:
				cout << "Breakfast";
				break;

			case 2:
				cout << "Lunch";
				break;

			case 3:
				cout << "Dinner";
				break;

			case 4:
				cout << "Snack";
				break;
			}
			cout.unsetf(ios::left);
			cout << " | "<< endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
}