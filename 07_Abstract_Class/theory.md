# Abstract Class & Pure Virtual Functions

## What is an Abstract Class?
A class that has **at least one pure virtual function** is called an abstract class. It cannot be instantiated — you cannot create objects of it directly.

## Pure Virtual Function
A virtual function with `= 0` — it has no body in the base class and **must** be overridden by child classes.

```cpp
virtual double area() = 0;   // pure virtual
```

## Why Abstract Classes?
- Forces child classes to implement certain methods
- Defines a common interface for all derived classes
- Acts like a contract — if you inherit, you must implement

## Syntax
```cpp
class Shape {
public:
    virtual double area() = 0;       // pure virtual
    virtual double perimeter() = 0;  // pure virtual

    void describe() {                // normal method — can have body
        cout << "Area = " << area() << "\n";
    }
};

// Shape s;   // ERROR — cannot instantiate abstract class
```

## Interface vs Abstract Class
| Feature | Abstract Class | Interface (in C++) |
|---|---|---|
| Data members | Can have | Usually none |
| Normal methods | Can have | Usually pure virtual only |
| Constructors | Can have | No |
| Multiple inheritance | Limited | Yes (pure abstract) |

In C++, a fully abstract class (all pure virtual) acts like an interface.

## Important Points
- Even one pure virtual function makes class abstract
- Child class must override ALL pure virtual functions, else it also becomes abstract
- Abstract class can have constructors (called by child)
- You can have pointers/references of abstract class type
