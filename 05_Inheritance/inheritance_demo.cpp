// Task: Child class inherits color and display from parent, adds its own area/perimeter

#include <iostream>
using namespace std;

class Shape {
public:
    string color;

    void setColor(string c) {
        color = c;
    }

    void display() {
        cout << "Color: " << color << "\n";
    }
};

// Rectangle IS-A Shape
class Rectangle : public Shape {
public:
    double length, width;

    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }

    void display() {
        Shape::display();   // call parent's display
        cout << "Area: " << area() << " | Perimeter: " << perimeter() << "\n";
    }
};

int main() {
    Rectangle r(5, 3);
    r.setColor("Red");    // inherited from Shape
    r.display();
    return 0;
}
