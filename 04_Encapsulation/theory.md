# Encapsulation

## What is Encapsulation?
Encapsulation means **bundling data and methods together** inside a class, and **restricting direct access** to the data from outside. Data is kept private and only accessible through public methods.

## Why Encapsulation?
- Protects data from accidental modification
- Allows validation before setting values
- Hides internal implementation (also called data hiding)
- Makes code easier to maintain

## Getters & Setters
```cpp
class Person {
private:
    int age;   // hidden from outside

public:
    void setAge(int a) {    // setter with validation
        if (a >= 0 && a <= 150)
            age = a;
    }

    int getAge() {          // getter
        return age;
    }
};
```

## Real Life Analogy
Think of a capsule (medicine) — the ingredients inside are hidden and protected. You just use it, you don't directly touch the chemicals inside.

Or think of an ATM — you can deposit/withdraw but you can't directly access the bank's database.

## Important Points
- Private data + public methods = encapsulation
- Setters can validate input before assigning
- Getters provide read-only access to private data
- Encapsulation leads to better security and maintainability

## Encapsulation vs Abstraction
| Encapsulation | Abstraction |
|---|---|
| Hides data using access specifiers | Hides complexity using abstract classes/interfaces |
| How data is stored is hidden | How something works is hidden |
| Achieved via private/public | Achieved via abstract classes & interfaces |
