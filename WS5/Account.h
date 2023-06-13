/*///////////////////////////////////////////////////////////////////////////
Name: Reginald Edward
Email: redward7@myseneca.ca
Student Number: 149047227
Date: June 10, 2023
Section: OOP244 NAA

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 

      //Set Account to an empty state
      void setEmpty();

   public:
      
      //Constructor to set values to an empty state
      Account();

      //Set the values of data members with the incoming arguments
      Account(int number, double balance);

      //Display the account info
      std::ostream& display()const;

      //Returns true if account is valid and if not it will return false
      operator bool() const;

      //Returns account number
      operator int() const;

      //Returns the balance 
      operator double() const;

      ////Returns true if account is new
      bool operator~() const;

      //Overload assignment operator so a NEW account can be set to an integer.
      Account& operator=(int number);

      //Overload assignment operator so a NEW account can be set to another account object
      Account& operator=(Account& anotherAccount);

      //Overload += operator to add deposits to account balance
      Account& operator+=(double deposit);

      //Overload -= operator to subtract withdrawls from account balance
      Account& operator-=(double withdrawl);

      //Overload the << operator to move funds from right account to the left
      Account& operator<<(Account& moveFundsFromAccount);

      //Overload the >> operator to move funds from the left account to the right account
      Account& operator>>(Account& moveFundsToAccount);

      //helper + operator that returns the sum of the balances of two accounts
      friend double operator+(const Account& firstAccount, const Account& secondAccount);

      //helper += operator that returns the value after the balance is added to it
      friend double& operator+=(double& addAmountInto, const Account& account);

   };    
   
}
#endif // SDDS_ACCOUNT_H_