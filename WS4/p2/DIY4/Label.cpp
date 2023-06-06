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
#include <stdio.h>
#include "cstring.h" 
#include "Label.h"


using namespace std;

namespace sdds {

	//Set deafault frame for Label
	void Label::setToDefault() {

		labelContent = nullptr;

		frame = new char[8 + 1];
		strCpy(frame, "+-+|+-+|");
	}

	//Use constructor to set the default frame
	Label::Label() {
		setToDefault();
	}

	//Set frame to frameArg
	Label::Label(const char* frameArg) {

		labelContent = nullptr;

		frame = new char[8 + 1];
		strCpy(frame, frameArg);
	}

	//Set frame to frameArg and labelcontent to content
	Label::Label(const char* frameArg, const char* content) {
		int labelContentLength;
		int frameLength;


		frame = nullptr;
		labelContent = nullptr;

		frameLength = strLen(frameArg);
		frame = new char[frameLength + 1];
		strCpy(frame, frameArg);

		labelContentLength = strLen(content);
		labelContent = new char[labelContentLength + 1];
		strCpy(labelContent, content);
	}

	//Destructor to deallocate memory for frame and labelContent
	Label::~Label() {
		delete[] frame;
		delete[] labelContent;
	}

	//Read label from console up to 70 characters
	void Label::readLabel() {
		char content[71];
		int labelContentLength;

		cin.getline(content, MAX_LABEL_CONTENT);
		labelContentLength = strLen(content);
				
		labelContent = new char[labelContentLength + 1];
		strCpy(labelContent, content);
	}


	//Print the labels
	std::ostream& Label::printLabel()const {

		if (labelContent != nullptr) {
			int i, totalLength;

			//Determine the max length of the label frame to know how many times specific character should repeat
			int frameLength = strLen(frame);
			int contentLength = strLen(labelContent);

			if (frameLength > contentLength) {
				totalLength = frameLength;
			}
			else {
				totalLength = contentLength;
			}

			//Display top portion of label
			for (i = 0; i <= totalLength + 2; i++) {
				if (i == 0) {
					cout << frame[0];
				}
				if (i > 0 && i <= totalLength + 2) {
					cout << frame[1];
				}

				if (i == totalLength + 2) {
					cout << frame[2];
				}
			}

			cout << endl;

			//Display second line of label
			for (i = 0; i <= totalLength + 3; i++) {
				if (i == 0) {
					cout << frame[7];
				}
				else if (i == totalLength + 3) {
					cout << frame[3];
				}
				else {
					cout << " ";
				}
			}

			cout << endl;

			//Display third line of label with label content
			cout << frame[7] << " " << labelContent;

			for (i = contentLength; i <= totalLength + 1; i++) {

				if (i == totalLength + 1) {
					cout << frame[3];
				}
				else {
					cout << " ";
				}
			}

			cout << endl;


			//Display fourth line of label
			for (i = 0; i <= totalLength + 3; i++) {
				if (i == 0) {
					cout << frame[7];
				}
				else if (i == totalLength + 3) {
					cout << frame[3];
				}
				else {
					cout << " ";
				}
			}
			
			cout << endl;

			//Display final line of label
			for (i = 0; i <= totalLength + 2; i++) {
				if (i == 0) {
					cout << frame[6];
				}
				if (i > 0 && i <= totalLength + 2) {
					cout << frame[5];
				}

				if (i == totalLength + 2) {
					cout << frame[4];
				}


			}
		}
		return std::cout;

	}
}