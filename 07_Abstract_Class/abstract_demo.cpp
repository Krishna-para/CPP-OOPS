// Task: Pure virtual area() and perimeter() force Rectangle and Circle to implement them

#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;

    void describe() {
        cout << "Area = " << area() << " | Perimeter = " << perimeter() << "\n";
    }
};

// Shape s;   // ERROR — can't instantiate abstract class

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() override { return 3.14159 * r * r; }
    double perimeter() override { return 2 * 3.14159 * r; }
};

class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double l, double w) : l(l), w(w) {}
    double area() override { return l * w; }
    double perimeter() override { return 2 * (l + w); }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 3);

    for (int i = 0; i < 2; i++)
        shapes[i]->describe();

    delete shapes[0];
    delete shapes[1];
    return 0;
}
