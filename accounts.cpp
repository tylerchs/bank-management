/*
    Name: Tyler Smith, ASSIGNMENT 5
    Description: Implementation of Account base class & 
                 Checkings/Savings derived classes
    Input: Customer name (string), account balance (double), interest rate (double)
    Output: Account information, withdrawal confirmations, balance updates

*/

// Libraries and use namespace standard
#include "accounts.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Account Implementation
// Default constructor implementation
Account::Account() {
    customerName  = "";
    accountBalance = 0.0;
    interestRate = 0.0;
}

// Parameterized constructor
Account::Account(string name, double amount, double rate) {
    customerName = name;
    accountBalance = amount;
    interestRate = rate;
}

string Account::getCustomerName() const {
    return customerName;
}
double Account::getAccountBalance() const {
    return accountBalance;
}
double Account::getInterestRate() const {
    return interestRate;
}

// Setter functions
void Account::setCustomerName(string name) {
    customerName = name;
}
void Account::setAccountBalance(double amount) {
    accountBalance = amount;
}
void Account::setInterestRate(double rate) {
    interestRate = rate;
}

void Account::compoundInterest() {
    double P0 = accountBalance;
    double r = interestRate / 100.0;
    double n = 365.0;
    double t = 1.0 / 365.0;
    
    double base = 1.0 + (r / n);
    double result = base;
    double P1 = P0 * result;
    
    accountBalance = (int)(P1 * 100.0 + 0.5) / 100.0;
}

// Checking Account Implementation
// Default Constructor
CheckingAccount::CheckingAccount() : Account() {
    // already initialized by calling base
}

// Parameterized constructor
CheckingAccount::CheckingAccount(string name, 
    double amount, double rate) : Account(name, amount, rate) {
        // base initializes
    }

// Defining pure virtuals
//Print acc information
void CheckingAccount::printAccountInfo() const {
    cout << "Checking account for customer " << 
        getCustomerName() << endl;
    cout << fixed << setprecision(2);
    cout << "Current balance: " << getAccountBalance() << endl;
    cout << "APR: " << getInterestRate() << "%" << endl;
}

bool CheckingAccount::checkAccount(double withdraw) {
    double amount = getAccountBalance();
    return amount >= withdraw;
}

void CheckingAccount::withdrawAccount(double withdraw) {
    bool check = checkAccount(withdraw);
    if (check) {
        setAccountBalance(getAccountBalance() - withdraw);
    }
}

// Savings Account Implementation
// Default constructor
SavingsAccount::SavingsAccount() : Account() {
    // base initialized
    withdrawalEvents = 0;
}

// param constructor
SavingsAccount::SavingsAccount(string name, 
    double amount, double rate) : Account(name, amount, rate) {
        // initialized in base
        withdrawalEvents = 0;
    }

// retrieve val for withdrawal events
int SavingsAccount::getWithdrawalEvents() {
    return withdrawalEvents;
}
// reset withdrawal events
void SavingsAccount::resetWithdrawalEvents() {
    withdrawalEvents = 0;
}

// pure virtuals
void SavingsAccount::printAccountInfo() const {
    cout << "Savings account for customer " << 
        getCustomerName() << endl;
    cout << fixed << setprecision(2);
    cout << "Current balance: " << getAccountBalance() << endl;
    cout << "APR: " << getInterestRate() << "%" << endl;
}

bool SavingsAccount::checkAccount(double amount) {
    return (getAccountBalance() >= amount && 
        withdrawalEvents < MAX_WITHDRAWALS);
}

// process withdrawal
void SavingsAccount::withdrawAccount(double withdraw) {
    bool check = checkAccount(withdraw);
    if (check) {
        setAccountBalance(getAccountBalance() - withdraw);
        withdrawalEvents++;
    }
}