#include "Account.hpp"
#include <iostream>

Account::Account(std::string name, std::string accNum, double initialBalance) {
    ownerName = name;
    accountNumber = accNum;
    balance = initialBalance >= 0 ? initialBalance : 0.0;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Successfully deposited $" << amount << "\n";
    } else {
        std::cout << "Invalid deposit amount!\n";
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Successfully withdrew $" << amount << "\n";
        return true;
    } else {
        std::cout << "Error: Insufficient funds or invalid amount!\n";
        return false;
    }
}

void Account::displayAccountDetails() const {
    std::cout << "--------------------------\n";
    std::cout << "Account Holder: " << ownerName << "\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Current Balance: $" << balance << "\n";
    std::cout << "--------------------------\n";
}

int Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}