// Task: Private data with validated getters/setters, block direct access

#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    void setAge(int a) {
        if (a < 0 || a > 150)
            cout << "Invalid age!\n";
        else
            age = a;
    }

    void setName(string n) {
        name = n;
    }

    int getAge() { return age; }
    string getName() { return name; }

    void display() {
        cout << name << " | Age: " << age << "\n";
    }
};

int main() {
    Person p;
    p.setName("Krishna");
    p.setAge(21);
    p.setAge(-5);       // invalid — will print error

    // p.age = 25;      // ERROR: private member not accessible
    // p.name = "test"; // ERROR: private member not accessible

    p.display();
    cout << "Name: " << p.getName() << "\n";
    cout << "Age: " << p.getAge() << "\n";
    return 0;
}
