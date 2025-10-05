/*
  Header for accounts classes
*/

#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <iostream>

using namespace std;

// define a constant for the maximum number of withdrawls for a savings account
#define MAX_WITHDRAWALS 2

// define base Account class
class Account {
private:
  string customerName;
  double accountBalance;
  double interestRate;

public:
  // default constructor
  Account();

  // parametrized constructor
  Account(string name, double amount, double rate);

  // getters and setters
  string getCustomerName() const;
  double getAccountBalance() const;
  double getInterestRate() const;
  void setCustomerName(string name);
  void setAccountBalance(double amount);
  void setInterestRate(double rate);

  // function to compound interest rate
  void compoundInterest();

  // pure virtual functions!
  // function to print account info
  virtual void printAccountInfo() const = 0;
  // function to check if account can be withdrawn from
  virtual bool checkAccount(double amount) = 0;
  // function to withdraw from account
  virtual void withdrawAccount(double amount) = 0;
};


class CheckingAccount : public Account {
public:
  // inherited constructors
  CheckingAccount();
  CheckingAccount(string name, double amount, double rate);
  // implement pure virtual functions
  void printAccountInfo() const;
  bool checkAccount(double amount);
  void withdrawAccount(double amount);
};


class SavingsAccount : public Account {
private:
  int withdrawalEvents;
public:
  // inherited constructors
  SavingsAccount();
  SavingsAccount(string name, double amount, double rate);
  // new functions
  int getWithdrawalEvents();
  void resetWithdrawalEvents();
  // implement pure virtual functions
  void printAccountInfo() const;
  bool checkAccount(double amount);
  void withdrawAccount(double amount);
};


#endif
