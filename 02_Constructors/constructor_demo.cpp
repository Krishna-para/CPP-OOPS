// Task: Show default, parameterized, and copy constructor in BankAccount class

#include <iostream>
using namespace std;

class BankAccount {
    int accountNumber;
    double balance;

public:
    // DEFAULT constructor
    BankAccount() {
        accountNumber = 0;
        balance = 0.0;
        cout << "Default constructor called\n";
    }

    // PARAMETERIZED constructor
    BankAccount(int accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
        cout << "Parameterized constructor called\n";
    }

    // COPY constructor
    BankAccount(const BankAccount& other) {
        accountNumber = other.accountNumber;
        balance = other.balance;
        cout << "Copy constructor called\n";
    }

    void display() {
        cout << "Acc: " << accountNumber << " | Bal: " << balance << "\n";
    }
};

int main() {
    BankAccount a1;                  // default constructor
    BankAccount a2(101, 5000);       // parameterized constructor
    BankAccount a3 = a2;             // copy constructor

    a1.display();
    a2.display();
    a3.display();
    return 0;
}
