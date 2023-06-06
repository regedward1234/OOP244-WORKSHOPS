/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: June 05, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h" 
#include "LabelMaker.h"

using namespace std;

namespace sdds {
	//Create an array of Labels
	LabelMaker::LabelMaker(int noOfLabels) {
		numberOfLabels = noOfLabels;
		labels = nullptr;
		
		if (numberOfLabels > 0) {

			labels = new Label[noOfLabels];
		}
	}

	//Deallocate memory for array of labels
	LabelMaker::~LabelMaker() {
		delete[] labels;
	}

	//Get contents of labels
	void LabelMaker::readLabels() {
		int i;

		cout << "Enter " << numberOfLabels << " labels:" << endl;

		for (i = 0; i < numberOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl;
			cout << "> ";
			labels[i].readLabel();
		}
	}

	//Display the labels
	void LabelMaker::printLabels() {
		int i;

		for (i = 0; i < numberOfLabels; i++) {
			labels[i].printLabel() << endl;
		}
	}

}