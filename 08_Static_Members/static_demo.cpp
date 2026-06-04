// Task: Track how many Person objects are alive at any point using static int count

#include <iostream>
using namespace std;

class Person {
    string name;

public:
    static int count;

    Person(string n) {
        name = n;
        count++;
    }

    ~Person() {
        count--;
    }

    static void showCount() {
        cout << "Total persons alive: " << count << "\n";
    }
};

int Person::count = 0;   // define outside class

int main() {
    Person::showCount();   // 0
    Person p1("Krishna");
    Person p2("Arjun");
    Person::showCount();   // 2
    {
        Person p3("Rahul");
        Person::showCount();  // 3
    }   // p3 destroyed here
    Person::showCount();   // 2
    return 0;
}
