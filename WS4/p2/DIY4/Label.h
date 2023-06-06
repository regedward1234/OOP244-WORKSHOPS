/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: June 05, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_Label_H
#define SDDS_Label_H
#define MAX_LABEL_CONTENT 71
namespace sdds {
	class Label {
		char* labelContent;
		char* frame;
		void setToDefault();
	public:
		
		//Constructor with no arguments to set default frame
		Label();

		//Constructor with one argument to set the frame to incoming argument
		Label(const char* frameArg);

		//Constructor with two arguments to set the frame to first argument and label content to second argument
		Label(const char* frameArg, const char* content);

		//Destructor to deallocate memory for frame and label content
		~Label();

		//Read label content from console
		void readLabel();

		//Print out the labels in specific format
		std::ostream& printLabel()const;
	};
}
#endif 
