/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: June 10, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
	void Account::setEmpty() {
		m_number = -1;
		m_balance = 0.0;
	}
	// New account
	Account::Account() {
		m_number = 0;
		m_balance = 0.0;
	}
	Account::Account(int number, double balance) {
		setEmpty();
		if (number >= 10000 && number <= 99999
			&& balance > 0) {
			m_number = number;
			m_balance = balance;
		}
	}
	std::ostream& Account::display() const {
		if (*this) {
			cout << " ";
			cout << m_number;
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << " ";
		}
		else if (~*this) {
			cout << "  NEW  |         0.00 ";
		}
		else {
			cout << "  BAD  |    ACCOUNT   ";
		}
		return cout;
	}

	//Returns true if account is valid and if not it will return false
	Account::operator bool() const {
		bool tempBool;
		if (m_number != 0 && m_number >= 10000 && m_number <= 99999 && m_balance >= 0) {
			tempBool = true;
		}
		else {
			tempBool = false;
		}
		return tempBool;
	}

	//Returns account number
	Account::operator int() const {
		return m_number;
	}

	//Returns the balance 
	Account::operator double() const {
		return m_balance;
	}

	//Returns true if account is new which is when account number is 0. Otherwise, it will return false
	bool Account::operator~() const {
		bool tempBool;
		if (m_number == 0) {
			tempBool = true;
		}
		else {
			tempBool = false;
		}
		return tempBool;
	}

	//Overload assignment operator so a NEW account can be set to an integer.
	Account& Account::operator=(int number) {

		//New account is set to 0 so check if it new account by hcecking if it 0
		/*if (m_number == 0) {
			if (number >= 10000 && number <= 99999) {
				m_number = number;
			}*/

			//Changed above commented code to try testing the overloaded operator ~
		if (~*this) {
			if (number >= 10000 && number <= 99999) {
				m_number = number;
			}
			else {
				setEmpty();
			}
		}
		return *this;
	}

	//Overload assignment operator so a NEW account can be set to another account object
	Account& Account::operator=(Account& anotherAccount) {

		//check if new account and that the other account transferring infromation from is a valid account
		/*if (m_number == 0 && anotherAccount.m_number != -1) {
			m_number = anotherAccount.m_number;
			m_balance = anotherAccount.m_balance;*/

			//Did same thing as commented code above but testing the overloaded operators for ~ and bool
		if (~*this && anotherAccount) {
			m_number = anotherAccount.m_number;
			m_balance = anotherAccount.m_balance;

			//balance and account number of other account will be set to 0 after transfer
			anotherAccount.m_balance = 0.0;
			anotherAccount.m_number = 0;

		}
		return *this;
	}

	//Overload += operator to add deposits to account balance
	Account& Account::operator+=(double deposit) {

		//Check if account number is valid and deposit not negative number
		/*if (m_number != -1 && deposit >= 0) {
			m_balance += deposit;
		}*/

		//Did the same thing as commented code above but used the overloaded operator bool
		if (*this && deposit >= 0) {
			m_balance += deposit;
		}
		return *this;
	}

	//Overload -= operator to subtract withdrawls from account balance 
	Account& Account::operator-=(double withdrawl) {

		//Check if there is enough balance for a withdrawl
		/*if (m_number != -1 && withdrawl > 0.0 && ((m_balance - withdrawl) >= 0)) {
			m_balance -= withdrawl;
		}*/

		//Did the same thing as commented code above but used the overloaded operator bool
		if (*this && withdrawl > 0.0 && ((m_balance - withdrawl) >= 0)) {
			m_balance -= withdrawl;
		}
		return *this;
	}

	//Overload the << operator to move funds from right account to the left
	Account& Account::operator<<(Account& moveFundsFromAccount) {

		//Check if its valid account and it is not the same account number
		/*if (m_number != -1 && moveFundsFromAccount.m_number != -1 && m_number != moveFundsFromAccount.m_number) {
			m_balance += moveFundsFromAccount.m_balance;*/

		//Did the same thing as commented code above but used the overloaded operator bool
		if (*this && moveFundsFromAccount && m_number != moveFundsFromAccount.m_number) {
			m_balance += moveFundsFromAccount.m_balance;

			//Set balance of other account to 0
			moveFundsFromAccount.m_balance = 0.0;
		}
		return *this;
	}

	//Overload the >> operator to move funds from the left account to the right account
	Account& Account::operator>>(Account& moveFundsToAccount) {

		//Check if its valid account and it is not the same account number
		/*if (moveFundsToAccount.m_number != -1 && m_number != -1 && moveFundsToAccount.m_number != m_number) {
			moveFundsToAccount.m_balance += m_balance;*/

		//Did the same thing as commented code above but used the overloaded operator bool
		if (moveFundsToAccount && *this && moveFundsToAccount.m_number != m_number) {
			moveFundsToAccount.m_balance += m_balance;

			//Set balance of other account to 0
			m_balance = 0.0;
		}
		return *this;
	}

	//helper + operator that returns the sum of the balances of two accounts
	double operator+(const Account& firstAccount, const Account& secondAccount) {

		//Add both account balances
		/*double balanceSum;
		balanceSum = firstAccount.m_balance + secondAccount.m_balance;*/

		//Do same thing as commented code above but use overloaded operator double
		double balanceSum;
		balanceSum = double(firstAccount) + double(secondAccount);

		return balanceSum;
	}

	//helper += operator that returns the value after the balance is added to it
	double& operator+=(double& addAmountInto, const Account& account) {

		//Add balance to amount
		/*addAmountInto += account.m_balance;*/

		//Do same thing as commented code above but use overloaded operator double
		addAmountInto += double(account);

		return addAmountInto;
	}
}