#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::all_of
#include "Account.hpp"

// Helper function to check if a string contains only digits
bool isNumeric(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

// Helper function using a reference to find an account in our vector
Account* findAccount(std::vector<Account>& accounts, std::string accNum) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNum) {
            return &accounts[i]; // Return a pointer to the matched account
        }
    }
    return nullptr; // Not found
}

int main() {
    std::vector<Account> bankAccounts;
    int choice;

    do {
        std::cout << "\n=== Simple Bank Management System ===\n";
        std::cout << "1. Create New Account\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Check Account Details\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        
        std::cin >> choice;

        // Check if the user entered something invalid for choice
        if (std::cin.fail()) {
            std::cin.clear(); // Reset error flag
            std::cin.ignore(10000, '\n'); // Discard bad input
            std::cout << "\n[!] Invalid input. Please enter a number from 1 to 5.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::string name;
                std::string accNum;
                double initialDeposit;

                // Clear newline left in buffer from std::cin >> choice
                std::cin.ignore(10000, '\n');

                std::cout << "Enter owner name: ";
                std::getline(std::cin, name);

                // Input loop to ensure account number contains ONLY digits
                while (true) {
                    std::cout << "Enter account number (digits only): ";
                    std::cin >> accNum;

                    if (isNumeric(accNum)) {
                        break; // Valid number, proceed
                    }
                    std::cout << "[!] Invalid account number. Please use numbers only.\n";
                }

                std::cout << "Enter initial deposit: ";
                while (!(std::cin >> initialDeposit) || initialDeposit < 0) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "[!] Invalid amount. Enter a positive number: ";
                }

                bankAccounts.push_back(Account(name, accNum, initialDeposit));
                std::cout << "Account created successfully!\n";
                break;
            }
            case 2: {
                std::string accNum; // Fixed typo (std::sting -> std::string)
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accNum;

                Account* accPtr = findAccount(bankAccounts, accNum);
                if (accPtr != nullptr) {
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;
                    accPtr->deposit(amount);
                } else {
                    std::cout << "Account not found!\n";
                }
                break;
            }
            case 3: {
                std::string accNum;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accNum;

                Account* accPtr = findAccount(bankAccounts, accNum);
                if (accPtr != nullptr) {
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;
                    accPtr->withdraw(amount);
                } else {
                    std::cout << "Account not found!\n";
                }
                break;
            }
            case 4: {
                std::string accNum; // Fixed typo (std::sting -> std::string)
                std::cout << "Enter account number: ";
                std::cin >> accNum;

                Account* accPtr = findAccount(bankAccounts, accNum);
                if (accPtr != nullptr) {
                    accPtr->displayAccountDetails();
                } else {
                    std::cout << "Account not found!\n";
                }
                break;
            }
            case 5:
                std::cout << "Thank you for using the Bank Management System. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}