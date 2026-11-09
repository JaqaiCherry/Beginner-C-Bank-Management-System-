#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account {
private:
    std::string ownerName;
    int accountNumber;
    double balance;

public:
    // Constructor
    Account(std::string name, int accNum, double initialBalance);

    // Member functions
    void deposit(double amount);
    bool withdraw(double amount); // Returns true if successful
    void displayAccountDetails() const;

    // Getter methods
    std::string getAccountNumber() const;
    double getBalance() const;
};

#endif