# Inheritance

## What is Inheritance?
Inheritance allows a class (child) to **acquire properties and methods** of another class (parent). It promotes code reusability.

## Syntax
```cpp
class Child : access_specifier Parent {
    // child-specific members
};
```

## Types of Inheritance
1. **Single** → one parent, one child
2. **Multilevel** → A → B → C (chain)
3. **Multiple** → child has two parents
4. **Hierarchical** → one parent, multiple children
5. **Hybrid** → combination of above

## Access Specifiers in Inheritance
| Parent member | public inheritance | protected inheritance | private inheritance |
|---|---|---|---|
| public | public | protected | private |
| protected | protected | protected | private |
| private | not inherited | not inherited | not inherited |

## IS-A Relationship
Inheritance models an IS-A relationship:
- Rectangle IS-A Shape ✅
- Car IS-A Vehicle ✅
- Dog IS-A Animal ✅

## Constructor in Inheritance
- Parent constructor is called **before** child constructor
- Destructor called in **reverse** — child first, then parent
- Use initializer list to call parent constructor:
```cpp
Child(int x) : Parent(x) { }
```

## Important Points
- `private` members of parent are NOT inherited
- Use `protected` if you want child to access parent's data directly
- `super` equivalent in C++ is `ParentClass::method()`
