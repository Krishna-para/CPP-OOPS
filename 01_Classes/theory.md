# Classes & Objects

## What is a Class?
A class is a **blueprint** or template for creating objects. It defines what data (attributes) an object will hold and what actions (methods) it can perform.

## What is an Object?
An object is an **actual instance** of a class — real memory is allocated when you create one.

## Syntax
```cpp
class ClassName {
    // private by default
    int data;

public:
    void method() { }
};

ClassName obj;  // object created
```

## Key Concepts
- **Data members** → variables inside a class (attributes)
- **Member functions** → functions inside a class (methods)
- **Access specifiers:**
  - `private` → only accessible inside the class (default)
  - `public` → accessible from anywhere
  - `protected` → accessible inside class and child classes

## Important Points
- Class definition ends with `;`
- Members are **private by default** in a class
- Members are **public by default** in a struct
- Object creation allocates memory on the stack
- `new` keyword creates object on the heap

## Real Life Analogy
- Class = blueprint of a house
- Object = actual house built from that blueprint
- Multiple objects can be created from one class, just like multiple houses from one blueprint
