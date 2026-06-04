# Static Members

## What are Static Members?
Static members **belong to the class**, not to any specific object. They are shared across all instances of the class.

## Static Data Members
- Only one copy exists regardless of how many objects are created
- Must be defined outside the class
- Initialized to 0 by default

```cpp
class Person {
public:
    static int count;   // declaration
};

int Person::count = 0;  // definition (outside class)
```

## Static Member Functions
- Can only access static data members
- Called using class name, not object
- No `this` pointer

```cpp
static void showCount() {
    cout << count;   // can access static members only
}

Person::showCount();   // called via class name
```

## When to Use Static?
- Counting objects (like tracking how many instances exist)
- Shared configuration values
- Utility functions that don't need object state

## Important Points
- Static members are created once when program starts
- Accessible via `ClassName::member` or via object (but class name preferred)
- Static functions cannot access non-static members (no `this` pointer)
- Static data members must be defined outside the class body

## Real Life Analogy
Think of a classroom — each student is an object. `studentCount` would be a static member because it belongs to the class concept, not any individual student.
