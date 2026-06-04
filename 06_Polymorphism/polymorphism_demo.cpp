// Task 6a: Overload add() method in Calculator for int, double, and 3 arguments
// Task 6b: Base class pointer calling Circle/Rectangle's display() via virtual functions

#include <iostream>
using namespace std;

// ===== COMPILE TIME POLYMORPHISM =====
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

// ===== RUNTIME POLYMORPHISM =====
class Shape {
public:
    virtual double area() {
        return 0;
    }

    virtual void display() {
        cout << "I am a shape\n";
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14159 * radius * radius;
    }

    void display() override {
        cout << "Circle | Area: " << area() << "\n";
    }
};

class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double l, double w) : l(l), w(w) {}

    double area() override {
        return l * w;
    }

    void display() override {
        cout << "Rectangle | Area: " << area() << "\n";
    }
};

int main() {
    // Compile time
    Calculator c;
    cout << c.add(2, 3) << "\n";
    cout << c.add(2.5, 3.5) << "\n";
    cout << c.add(1, 2, 3) << "\n";

    // Runtime
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 3);

    s1->display();   // Circle's display — decided at runtime
    s2->display();   // Rectangle's display

    delete s1;
    delete s2;
    return 0;
}
