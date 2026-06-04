# Destructor

## What is a Destructor?
A destructor is a **special function** that is automatically called when an object goes out of scope or is explicitly deleted. It is used to release resources held by the object.

## Rules
- Same name as the class, preceded by `~` (tilde)
- No return type, no parameters
- Cannot be overloaded — only one destructor per class
- Called automatically when object is destroyed

## Syntax
```cpp
~ClassName() {
    // cleanup code
}
```

## When is it Called?
- When a local object goes out of scope (end of block `}`)
- When a dynamically allocated object is deleted using `delete`
- When the program ends (for global objects)

## Order of Destruction
Objects are destroyed in **reverse order** of creation — like a stack (LIFO).

```
Created: a1 → a2 → a3
Destroyed: a3 → a2 → a1
```

## Why is it Important?
- Free dynamically allocated memory (`delete ptr`)
- Close file handles
- Release network connections
- Without destructor, memory leaks can occur

## Important Points
- If your class has **pointer members**, always write a destructor to free memory
- Compiler provides a default destructor if you don't write one
- Virtual destructor is needed in base class when using polymorphism
