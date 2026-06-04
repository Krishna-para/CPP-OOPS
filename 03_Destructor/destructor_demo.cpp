// Task: Show when destructor gets called using BankAccount creation and destruction

#include <iostream>
using namespace std;

class BankAccount {
    int accountNumber;
    double balance;

public:
    BankAccount(int accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
        cout << "Account " << accountNumber << " created\n";
    }

    ~BankAccount() {
        cout << "Account " << accountNumber << " closed\n";
    }
};

int main() {
    BankAccount a1(101, 5000);
    BankAccount a2(102, 8000);
    {
        BankAccount a3(103, 3000);
        cout << "Inside block\n";
    }   // a3 destroyed here
    cout << "Outside block\n";
    // a2 and a1 destroyed here in reverse order
    return 0;
}

// Output:
// Account 101 created
// Account 102 created
// Account 103 created
// Inside block
// Account 103 closed   <- a3 destroyed first (end of block)
// Outside block
// Account 102 closed   <- reverse order
// Account 101 closed
