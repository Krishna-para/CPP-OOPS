# 11. Exception Handling in C++

## What is Exception Handling?

Exception handling is a mechanism to handle **runtime errors** gracefully without crashing the program. Instead of abrupt termination, C++ allows you to *throw*, *catch*, and *handle* errors in a structured way.

---

## Why Use Exception Handling?

| Without Exceptions | With Exceptions |
|--------------------|-----------------|
| Program crashes on error | Error is caught and handled |
| Error codes everywhere | Clean separation of logic & error handling |
| Hard to trace error origin | Stack unwinding gives clear context |

---

## Key Keywords

| Keyword | Purpose |
|---------|---------|
| `try` | Block of code that might throw an exception |
| `throw` | Used to raise/trigger an exception |
| `catch` | Block that handles the thrown exception |

---

## Basic Syntax

```cpp
try {
    // Code that might throw
    throw <value>;
}
catch (<type> variable) {
    // Handle the exception
}
```

---

## Types of Exceptions

### 1. Built-in / Primitive Exceptions
You can throw any primitive type:
```cpp
throw 42;          // int
throw 3.14;        // double
throw "Error!";    // const char*
```

### 2. Standard Library Exceptions (`<stdexcept>`)

| Exception Class | Use Case |
|-----------------|----------|
| `std::exception` | Base class for all standard exceptions |
| `std::runtime_error` | Errors detectable only at runtime |
| `std::logic_error` | Errors in program logic |
| `std::out_of_range` | Index/value out of valid range |
| `std::invalid_argument` | Invalid argument passed to function |
| `std::overflow_error` | Arithmetic overflow |
| `std::bad_alloc` | Memory allocation failure (`new` fails) |

### 3. User-Defined Exceptions
Custom exception classes by inheriting from `std::exception`:
```cpp
class MyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "My custom error occurred!";
    }
};
```

---

## Multiple Catch Blocks

You can have multiple `catch` blocks for different exception types:

```cpp
try {
    // risky code
}
catch (int e)               { /* handle int exceptions */ }
catch (std::string& e)      { /* handle string exceptions */ }
catch (std::exception& e)   { /* handle standard exceptions */ }
catch (...)                 { /* catch-all handler */ }
```

> ⚠️ **Order matters!** Always place more specific exceptions before general ones. The `catch(...)` block should always be last.

---

## Stack Unwinding

When an exception is thrown, C++ **unwinds the call stack** — it exits all active function scopes between the `throw` and the matching `catch`, calling destructors along the way.

```
main()
  └─> functionA()
        └─> functionB()   ← exception thrown here
              └─> functionC()
```

If `functionC()` throws and only `main()` has a `catch`, C++ unwinds `functionC → functionB → functionA` before reaching the handler.

---

## Re-throwing Exceptions

You can re-throw a caught exception to pass it up the call stack:

```cpp
catch (std::exception& e) {
    std::cerr << "Logging: " << e.what() << std::endl;
    throw; // re-throws the same exception
}
```

---

## `noexcept` Specifier

Tells the compiler (and caller) that a function will **not throw**:

```cpp
int safeAdd(int a, int b) noexcept {
    return a + b;
}
```

> If a `noexcept` function throws anyway, `std::terminate()` is called immediately.

---

## Exception Safety Guarantees

| Level | Guarantee |
|-------|-----------|
| **No-throw** | Function never throws (use `noexcept`) |
| **Strong** | If exception occurs, state is rolled back (no side effects) |
| **Basic** | No resource leaks, but state may change |
| **None** | No guarantees — avoid this |

---

## RAII and Exceptions

**Resource Acquisition Is Initialization (RAII)** — resources are tied to object lifetimes. When an exception unwinds the stack, destructors run automatically, cleaning up resources.

```cpp
// Instead of raw pointers (leak-prone on exception):
int* p = new int(10);  // ❌ leaks if exception thrown before delete

// Use smart pointers (RAII):
std::unique_ptr<int> p = std::make_unique<int>(10);  // ✅ auto-cleaned
```

---

## Common Mistakes

- ❌ Catching by value for large objects (prefer `catch (const MyException& e)`)
- ❌ Swallowing exceptions silently in empty `catch` blocks
- ❌ Throwing exceptions from destructors (causes `std::terminate`)
- ❌ Using exceptions for normal control flow (use them only for *exceptional* cases)

---

## Summary

```
try     →  "Attempt this risky operation"
throw   →  "Something went wrong, here's the error"
catch   →  "I'll handle that error here"
```

Exception handling separates **error detection** from **error handling**, making code cleaner, safer, and easier to maintain.
