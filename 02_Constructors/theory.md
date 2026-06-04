# Constructors

## What is a Constructor?
A constructor is a **special function** that is automatically called when an object is created. It is used to initialize the object's data members.

## Rules
- Same name as the class
- No return type (not even void)
- Called automatically on object creation
- Can be overloaded

## Types of Constructors

### 1. Default Constructor
- No parameters
- Compiler provides one automatically if you don't write any constructor
- If you write ANY constructor yourself, compiler stops generating the default one

```cpp
BankAccount() {
    accountNumber = 0;
    balance = 0.0;
}
```

### 2. Parameterized Constructor
- Takes arguments to initialize data members
```cpp
BankAccount(int accNo, double bal) {
    accountNumber = accNo;
    balance = bal;
}
```

### 3. Copy Constructor
- Creates a new object as a copy of an existing object
- Takes a **const reference** to the same class
```cpp
BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    balance = other.balance;
}
```

## Constructor Initialization List
Faster and preferred way to initialize:
```cpp
BankAccount(int accNo, double bal) : accountNumber(accNo), balance(bal) {}
```

## Important Points
- If you define a parameterized constructor but no default constructor, `BankAccount acc;` will give an error
- Copy constructor is called when: object is passed by value, returned by value, or explicitly copied
- Shallow copy vs Deep copy matters when class has pointer members
