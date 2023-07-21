// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 2.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Reginald           2023/07/04           Added the read write and overloaded operators
// Reginald           2023/07/21           Took out ignore at end of read and modified systemYear and systemToToday
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>


using namespace std;
#include "Date.h"
namespace sdds {
	bool sdds_test = false;
	int sdds_year = 2023;
	int sdds_mon = 12;
	int sdds_day = 25;

	bool Date::validate() {
		errCode(NO_ERROR);
		if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
			errCode(YEAR_ERROR);
		}
		else if (m_mon < 1 || m_mon > 12) {
			errCode(MON_ERROR);
		}
		else if (m_day < 1 || m_day > mdays()) {
			errCode(DAY_ERROR);
		}
		return !bad();
	}
	int Date::mdays()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
		mon--;
		return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
	}
	int Date::systemYear()const {
		int theYear = sdds_year;
		if (!sdds_test) {
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			theYear = lt.tm_year + 1900;
		}
		return theYear;
	}
	void Date::setToToday() {
		if (sdds_test) {
			m_day = sdds_day;
			m_mon = sdds_mon;
			m_year = sdds_year;
		}
		else {
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			m_day = lt.tm_mday;
			m_mon = lt.tm_mon + 1;
			m_year = lt.tm_year + 1900;
		}
		errCode(NO_ERROR);
	}
	int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
		int ty = m_year;
		int tm = m_mon;
		if (tm < 3) {
			ty--;
			tm += 12;
		}
		return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
	}
	Date::Date() :m_CUR_YEAR(systemYear()) {
		setToToday();
	}
	Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
		m_year = year;
		m_mon = mon;
		m_day = day;
		validate();
	}
	const char* Date::dateStatus()const {
		return DATE_ERROR[errCode()];
	}
	int Date::currentYear()const {
		return m_CUR_YEAR;
	}
	void Date::errCode(int readErrorCode) {
		m_ErrorCode = readErrorCode;
	}
	int Date::errCode()const {
		return m_ErrorCode;
	}
	bool Date::bad()const {
		return m_ErrorCode != 0;
	}

	ostream& operator<<(ostream& os, const Date& RO) {
		return RO.write(os);
	}
	istream& operator>>(istream& is, Date& RO) {
		return RO.read(is);
	}

	istream& Date::read(std::istream& is) {

		// clear error code by setting it to NO_ERROR which is a global const
		m_ErrorCode = NO_ERROR;

		// read the year
		is >> m_year;
		// ignore single character
		is.ignore();
		// read month
		is >> m_mon;
		// ignore single character
		is.ignore();
		// read day
		is >> m_day;
		
		if (is.fail()) {
			m_ErrorCode = CIN_FAILED;
			is.clear();
		}
		else {
			// validate the values enetered using validate function
			validate();
		}
		return is;
	}

	ostream& Date::write(std::ostream& os)const {
		// use bad function to see if in bad state and if it is use datestatus function to print datestatus
		if (bad()) {
			os << dateStatus();
		}
		// if not in bad state print out the date in following format
		else {
			os << m_year;
			os << "/";
			os.width(2);
			os.fill('0');
			os << m_mon;
			os << "/";
			os.width(2);
			os << m_day;
			os.fill(' ');
		}
		return os;
	}

	// compare the date to see if they are equal
	bool Date::operator==(const Date& anotherDate) const {
		bool temp;

		if (daysSince0001_1_1() == anotherDate.daysSince0001_1_1()) {
			temp = true;
		}

		else {
			temp = false;
		}

		return temp;
	}

	// compare the date to see if they are not equal
	bool Date::operator!=(const Date& anotherDate) const {
		bool temp;

		if (daysSince0001_1_1() != anotherDate.daysSince0001_1_1()) {
			temp = true;
		}

		else {
			temp = false;
		}

		return temp;
	}

	// compare the date to see if current date is greater than or equal to incoming date
	bool Date::operator>=(const Date& anotherDate) const {
		bool temp;

		if (daysSince0001_1_1() >= anotherDate.daysSince0001_1_1()) {
			temp = true;
		}

		else {
			temp = false;
		}

		return temp;
	}

	// compare the date to see if current date is less than or equal to incoming date
	bool Date::operator<=(const Date& anotherDate) const {
		bool temp;

		if (daysSince0001_1_1() <= anotherDate.daysSince0001_1_1()) {
			temp = true;
		}

		else {
			temp = false;
		}

		return temp;
	}

	// compare the date to see if current date is less than to incoming date
	bool Date::operator<(const Date& anotherDate) const {
		bool temp;

		if (daysSince0001_1_1() < anotherDate.daysSince0001_1_1()) {
			temp = true;
		}

		else {
			temp = false;
		}

		return temp;
	}

	// compare the date to see if current date is greater than to incoming date
	bool Date::operator>(const Date& anotherDate) const {
		bool temp;

		if (daysSince0001_1_1() > anotherDate.daysSince0001_1_1()) {
			temp = true;
		}

		else {
			temp = false;
		}

		return temp;
	}

	// return different between two dates
	int Date::operator-(const Date& anotherDate) const {
		int temp;

		temp = daysSince0001_1_1() - anotherDate.daysSince0001_1_1();
		return temp;
	}

	// if date is valid return true
	Date::operator bool() const {
		bool temp;

		if (bad()) {
			temp = false;
		}

		else {
			temp = true;
		}
		
		return temp;
	}
}
