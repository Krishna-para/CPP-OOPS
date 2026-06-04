# Operator Overloading

## What is Operator Overloading?
Operator overloading allows you to **redefine the behavior of operators** (+, -, *, >, <, ==, etc.) for your custom classes.

## Syntax
```cpp
ReturnType operator+(const ClassName& other) {
    // define what + means for this class
}
```

## Example
```cpp
Employee e1("Krishna", 50000);
Employee e2("Arjun", 70000);

Employee combined = e1 + e2;   // uses overloaded +
```

## Commonly Overloaded Operators
| Operator | Use case |
|---|---|
| `+`, `-`, `*` | Math operations on objects |
| `==`, `!=` | Comparing objects |
| `>`, `<` | Sorting/ranking |
| `<<`, `>>` | Input/output stream |
| `[]` | Array-style access |
| `=` | Assignment |

## Operators That CANNOT Be Overloaded
- `::` (scope resolution)
- `.` (member access)
- `.*` (pointer to member)
- `?:` (ternary)
- `sizeof`

## Rules
- Cannot change the number of operands
- Cannot change operator precedence
- At least one operand must be a user-defined type
- Cannot create new operators

## Important Points
- Keeps code readable and intuitive
- `<<` and `>>` must be overloaded as **friend functions** (because left operand is `ostream`/`istream`)
- Overloading `=` is needed when class has pointer members (deep copy)
