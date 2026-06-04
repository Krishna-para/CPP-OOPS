# Friend Functions & Classes

## What is a Friend Function?
A friend function is a **non-member function** that has access to the private and protected members of a class. It is declared inside the class using the `friend` keyword.

## Syntax
```cpp
class MyClass {
private:
    int data;

public:
    friend void showData(MyClass obj);   // declaration inside class
};

void showData(MyClass obj) {   // definition outside — NOT a member
    cout << obj.data;          // can access private member
}
```

## Why Friend Functions?
- Needed when overloading `<<` and `>>` operators (left operand is `ostream`, not your class)
- Useful for operations involving two different classes
- Gives controlled access without making data public

## Friend Class
An entire class can be made a friend — all its methods get access to the other class's private members.

```cpp
class B;   // forward declaration

class A {
    int x;
    friend class B;   // B can access A's private members
};

class B {
public:
    void show(A obj) {
        cout << obj.x;   // valid — B is friend of A
    }
};
```

## << Operator Overloading (Why Friend?)
`cout << obj` means `operator<<(cout, obj)`. The left operand is `ostream`, not your class — so it can't be a member function of your class. It must be a standalone function, declared as friend to access private data.

```cpp
friend ostream& operator<<(ostream& out, const Time& t);
```

## Important Points
- Friendship is **not inherited** — child class doesn't get friend's access
- Friendship is **not mutual** — if A is friend of B, B is not automatically friend of A
- Friendship should be used sparingly — it breaks encapsulation
- Friend functions are declared inside class but defined outside
