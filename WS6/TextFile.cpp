/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: July 03, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	Line::operator const char* () const {
		return (const char*)m_value;
	}
	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}
	Line::~Line() {
		delete[] m_value;
	}

	void TextFile::setEmpty() {
		// delete dynamic array of textLines and set to null ptr
		delete[] m_textLines;
		m_textLines = nullptr;

		// delete dynamic array of textLines and set to null ptr
		delete[] m_filename;
		m_filename = nullptr;

		// set number of lines to 0
		m_noOfLines = 0;
	}

	void TextFile::setFilename(const char* fname, bool isCopy) {
		char prefix[3] = "C_";

		if (isCopy == false) {
			delete[] m_filename;
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}

		if (isCopy == true) {
			delete[] m_filename;
			m_filename = new char[strLen(fname) + 3]; //Add space for string and null terminator
			strCpy(m_filename, prefix);
			strCat(m_filename, fname);
		}
	}

	void TextFile::setNoOfLines() {

		// open the file with name in m_filename
		ifstream file(m_filename);

		char ch;
		m_noOfLines = 0;

		// read file character by character and increase noOfLines when new line characte reached
		while (file.get(ch)) {
			if (ch == '\n') {
				m_noOfLines++;
			}
		}
	

		if (m_noOfLines == 0) {
			delete[] m_filename;
			m_filename = nullptr;
		}
		else {
			// add one to new line just in case the lalst line does not have a new line character
			m_noOfLines++;
		}

	}


	//Need to relook at this function
	void TextFile::loadText() { 

		// if m_file name is null do nothing
		if (m_filename == nullptr) {

		}

		// if m_filename is not null 
		if (m_filename != nullptr) {

			// prevent memory leak delete textLine
			delete[] m_textLines;
			m_textLines = new Line[m_noOfLines];

			// create local instande of ifstream
			ifstream file(m_filename);
                
			    // define the string object to accept the input
				string line;
				unsigned i = 0;
				// extrct the input using getline helper function
				while (getline(file, line)) {
					// use line.c_str() to assign a c-style string
					m_textLines[i] = line.c_str();
					i++;
				}
				m_noOfLines = i;
		}
	}

	void TextFile::saveAs(const char* fileName)const {
		ofstream file(fileName);

		if (file) {
			for (unsigned i = 0; i < m_noOfLines; i++) {
				file << m_textLines[i] << endl;
			}
		}
	}

	TextFile::TextFile(unsigned pageSize) {
		// create empty TextFile and initialize m_pageSize to incoming argument
		m_filename = nullptr;
		m_textLines = nullptr;
		m_noOfLines = 0;
		m_pageSize = pageSize;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize) {
		// create empty TextFile and initialize m_pageSize to incoming argument
		m_filename = nullptr;
		m_textLines = nullptr;
		m_noOfLines = 0;
		m_pageSize = pageSize;

		// if filename not null ptr set the filename, number of lines, and load text
		if (filename != nullptr) {
			setFilename(filename);
			setNoOfLines();
			loadText();
		}
	}

	// copy constructor
	TextFile::TextFile(const TextFile& text) {
		m_filename = nullptr;
		m_textLines = nullptr;
		m_noOfLines = 0;
		m_pageSize = text.m_pageSize;
	

		if (text.m_filename != nullptr) {
			setFilename(text.m_filename, true);
			text.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}
	}

	TextFile& TextFile:: operator=(const TextFile& text) {
		// check for self assignment
		if (this != &text) {

			// deallocate previously allocated memory
			delete[] m_textLines;
			m_textLines = nullptr;

			// check of the current and incoming TextFiles are valid
			if (text.m_filename != nullptr && m_filename != nullptr) {
				//setFilename(text.m_filename, true);
				text.saveAs(m_filename);
				setNoOfLines();
				loadText();
			}
		}

		return *this;
	}

	TextFile:: ~TextFile() {
		delete[] m_filename;
		delete[] m_textLines;

	}

	unsigned TextFile::lines()const {
		return m_noOfLines;
	}

	std::ostream& TextFile::view(std::ostream& ostr)const {
		char symbol = '=';
		unsigned checkPrintedLines = 0;

		if (m_filename != nullptr && m_textLines != nullptr) {
			ostr << m_filename << endl;
		

			for (int i = 0; i < strLen(m_filename); i++) {
				ostr << symbol;
			}
			ostr << endl;

		
			for (unsigned i = 0; i < m_noOfLines; i++) {
				ostr << m_textLines[i] << endl;
				checkPrintedLines++;

				if (checkPrintedLines == m_pageSize) {	
					ostr << "Hit ENTER to continue...";
					cin.ignore(1000, '\n');
					checkPrintedLines = 0;
				}
			}
		}
		return ostr;
	}

	std::istream& TextFile::getFile(std::istream& istr) {
		// read file name 
		string file;
		istr >> file;
		istr.ignore(10000, '\n');

		setFilename(file.c_str());
		setNoOfLines();
		loadText();
		return istr;
	}

	const char* TextFile::operator[](unsigned index)const {

		
		if (m_textLines != nullptr && m_noOfLines != 0) {
			index %= m_noOfLines;
			return m_textLines[index];
		}
		else {
			return nullptr;
		}
	}

	TextFile::operator bool()const {
		bool temp;

		if (m_filename != nullptr && m_textLines != nullptr) {
			temp = true;
		}
		else {
			temp = false;
		}

		return temp;
	}

	const char* TextFile::name()const {
		return m_filename;
	}

	ostream& operator<<(ostream& ostr, const TextFile& text) {
		return text.view(ostr);
	}

	std::istream& operator>>(std::istream& istr, TextFile& text) {
		return text.getFile(istr);
	}
}