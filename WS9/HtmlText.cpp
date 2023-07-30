/***********************************************************************
// Version 1.0
// Description:
/// Name: Reginald Edward
// Email: redward7@myseneca.ca
// Student Number: 149047227
// Date: July 27, 2023
// Section: OOP244 NAA
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Reginald         2023/07/27      Implement the function except the write
//Reginald         2023/07/30      Fixed the copy constructor and added write function
///////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include "HtmlText.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	// invoke the constructor for Text
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
		m_title = nullptr;
		if(title != nullptr){
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
	}

	// copy constructor
	HtmlText::HtmlText(const HtmlText& other) : Text(other)
	{
		// initialize m_title to nullptr
		m_title = nullptr;
		// copy incoming argument
		if (other.m_title) {
			m_title = new char[strLen(other.m_title) + 1];
			strCpy(m_title, other.m_title);
		}
	}

	// copy assignment operator
	HtmlText& HtmlText::operator=(const HtmlText& other) {
		// invoke copy assignment operator of base class
		Text::operator=(other);
		if (this != &other) {
			delete[] m_title;
			if (other.m_title) {
				m_title = new char[strLen(other.m_title) + 1];
				strCpy(m_title, other.m_title);
			}
			else {
				m_title = nullptr;
			}
		}
		return *this;
	}

	// destructor for HtmlText
	HtmlText::~HtmlText() {
		delete[] m_title;
	}

	// display to screen
	void HtmlText::write(std::ostream& os)const {
		// set MS for multiple spaces false
		bool MS = false;
		
		os << "<html><head><title>";
		// if m_title not nullptr display title
		if (m_title != nullptr) {
			os << m_title;
		}
		else {
			os << "No Title";
		}
		
		os << "</title></head>\n<body>\n";

		// if m_title not null ptr display h1 tags around title
		if (m_title != nullptr) {
			os << "<h1>" << m_title << "</h1>\n";
		}
		
		int i = 0;
		// use overloaded index operator to get access to m_content
		char& ch = (*this)[i];
		
		// loop through each character as long as not null terminated  
		while (ch != '\0') {

			// check if each character meets specific req and replace them
			if (ch == ' ') {
				if (MS == true) {
					os << "&nbsp;";
				}
				else {
					MS = true;
					os << (' ');
				}
			}

			else if (ch == '<') {
				os << "&lt;";
				MS = false;
			}

			else if (ch == '>') {
				os << "&gt;";
				MS = false;
			}

			else if (ch == '\n') {
				os << "<br />\n";
				MS = false;
			}

			else {
				os << ch;
				MS = false;
			}
			ch = (*this)[++i];
		}
		os << "</body>\n</html>";
	}
}