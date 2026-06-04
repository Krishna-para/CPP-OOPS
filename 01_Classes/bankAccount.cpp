// Task: Create a BankAccount class with account number & balance
// Implement deposit, withdraw, and display methods

#include <iostream>
using namespace std;

class BankAccount {
    // private data members
    int accountNumber;
    double balance;

public:
    void setAccount(int accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient funds!\n";
        else
            balance -= amount;
    }

    void display() {
        cout << "Account No: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
    }
};

int main() {
    BankAccount acc;          // object created
    acc.setAccount(101, 5000);
    acc.deposit(1000);
    acc.withdraw(200);
    acc.display();
    return 0;
}
