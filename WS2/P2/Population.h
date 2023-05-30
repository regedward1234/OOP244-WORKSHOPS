/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: May 25, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
	
	struct PostalPop {
		char* postalCode;
		int population;
	
	};
	
	void sort();
	bool load(PostalPop& postalPops);
	bool load(const char* filename);
	void display(const PostalPop& postalPop);
	void display();
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_