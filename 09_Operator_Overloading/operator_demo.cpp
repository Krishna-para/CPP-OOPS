// Task: Overload + to combine salaries and > to compare two employees

#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    double salary;

    Employee(string n, double s) : name(n), salary(s) {}

    // + operator: combine salaries
    Employee operator+(const Employee& other) {
        return Employee("Combined", salary + other.salary);
    }

    // > operator: compare salaries
    bool operator>(const Employee& other) {
        return salary > other.salary;
    }

    void display() {
        cout << name << " | Salary: " << salary << "\n";
    }
};

int main() {
    Employee e1("Krishna", 50000);
    Employee e2("Arjun", 70000);

    Employee combined = e1 + e2;
    combined.display();   // Combined | 120000

    if (e2 > e1)
        cout << e2.name << " earns more\n";
    else
        cout << e1.name << " earns more\n";

    return 0;
}
