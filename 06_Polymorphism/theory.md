# Polymorphism

## What is Polymorphism?
Polymorphism means **one name, many forms**. The same function behaves differently based on context or object type.

## Types

### 1. Compile-time Polymorphism (Static)
Resolved at **compile time**. Achieved via:
- **Function Overloading** — same name, different parameters
- **Operator Overloading** — redefine operators for custom types

```cpp
int add(int a, int b)          // version 1
double add(double a, double b) // version 2
int add(int a, int b, int c)   // version 3
```

### 2. Runtime Polymorphism (Dynamic)
Resolved at **runtime**. Achieved via:
- **Virtual functions** + Inheritance
- Base class pointer pointing to derived class object

```cpp
Shape* s = new Circle(5);
s->area();   // calls Circle's area — decided at runtime
```

## Virtual Functions
- `virtual` keyword enables runtime dispatch
- Without `virtual`, base class pointer always calls base class method
- `override` keyword (C++11) confirms you're overriding a virtual function

```cpp
class Shape {
public:
    virtual double area() { return 0; }
};

class Circle : public Shape {
public:
    double area() override { return 3.14 * r * r; }
};
```

## VTable (Virtual Table)
- Compiler creates a hidden table of function pointers for each class with virtual functions
- At runtime, correct function is looked up from VTable
- This is why virtual functions have slight overhead

## Important Points
- Function overloading = same class, different params
- Function overriding = different class (parent-child), same signature
- `virtual` is needed for runtime polymorphism
- Pure virtual (`= 0`) makes class abstract
