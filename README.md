# OOP Matrix Library (C++)

This project implements a **2D Matrix class in C++** using Object-Oriented Programming.  
It includes constructors, copy constructor, destructor, exception handling, and rich operator overloading.

## Features
- Rule of Three: constructor, copy constructor, destructor (deep copy).
- Operator overloading: `+`, `-`, `*` (matrix×matrix and scalar×matrix), `=`, `==`, `<<`, `>>`, `[]`.
- Exception handling for invalid sizes and dimension mismatches.
- Casting operator to `double` → returns sum of all elements.
- Associativity checks (e.g., `(A+B)-C`).

## Example Usage
```cpp
MyMatrix A(3,3), B(3,3);
std::cin >> A >> B;

MyMatrix C = A + B;
MyMatrix D = 3 * C;

if (A == B) 
    std::cout << "Equal\n";

double sum = (double)D;  // sum of elements
std::cout << D;
