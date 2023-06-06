/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: June 05, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_LabelMaker_H
#define SDDS_LabelMaker_H
#include "Label.h"

namespace sdds {
	class LabelMaker {
		int numberOfLabels;
		Label* labels;

	public:
		
		//Creates an array of labels 
		LabelMaker(int noOfLabels);

		//Destrcutor to  deallocate memory for labels
		~LabelMaker();

		//Read contents of labels
		void readLabels();

		//Display labels
		void printLabels();
	};

}
#endif 
