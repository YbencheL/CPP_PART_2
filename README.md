# CPP_PART_2

This repository contains a set of C++ exercises covering the second part of the C++ modules series. The projects focus on object-oriented programming, exceptions, templates, STL containers, and algorithmic problem solving using the C++98 standard.

The code is organized by module and exercise:

## Repository structure

### C05 — Bureaucrats and Forms
- **ex00:** `Bureaucrat` class with grade validation and exception handling.
- **ex01:** `Form` class with signing requirements and grade checks.
- **ex02:** Abstract form hierarchy with `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`.
- **ex03:** `Intern` class that creates forms.

### C06 — Type Conversions and Serialization
- **ex00:** `ScalarConverter` converts input values to `char`, `int`, `float`, and `double`.
- **ex01:** `Serializer` and `Data` for pointer serialization and deserialization.
- **ex02:** Runtime type identification using a base class and derived classes.

### C07 — Templates
- **ex00:** Generic `swap`, `min`, and `max` functions.
- **ex01:** Generic iteration utility.
- **ex02:** `Array` template class with bounds checking.

### C08 — STL and Iterators
- **ex00:** `easyfind` searches for a value in a container.
- **ex01:** `Span` stores numbers and calculates the shortest and longest spans.
- **ex02:** `MutantStack` extends stack-like behavior with iterators.

### C09 — Advanced Exercises
- **ex00:** Bitcoin exchange calculator using CSV data and input validation.
- **ex01:** Reverse Polish Notation calculator.
- **ex02:** `PmergeMe` integer sorting exercise.

## Build and run

Each exercise has its own `Makefile`. Build and run an exercise from its directory. For example:

```bash
cd C05/ex00
make
./bureaucrat
```

Common Makefile targets include:

```bash
make
make clean
make fclean
make re
```

The executable name may vary by exercise; check its `Makefile` if needed.

## Requirements

- A C++ compiler with C++98 support
- GNU Make
- A Unix-like environment with standard build tools

## About

The exercises progress through object-oriented programming, exceptions, type conversions, templates, STL containers, and algorithms. Each exercise is designed to be built independently from its own directory.
