# Advanced Programming Course Projects - University of Tehran

## Overview

This repository contains a series of assignments and projects for the **Advanced Programming** course (APS02) at the **University of Tehran**. Each project focuses on different areas of programming, including data processing, algorithm implementation, object-oriented principles, and interactive simulations.

---

## Repository Structure

- **CA0**: [Basic Algorithmic Logic](#ca0---basic-algorithmic-logic)
- **CA1**: [Day Tracking](#ca1---day-tracking)
- **CA2**: [Matrix Operations](#ca2---matrix-operations)
- **CA3**: [Schedule Planner](#ca3---schedule-planner)
- **CA4**: [Basic String Manipulation](#ca4---basic-string-manipulation)
- **CA5**: [Turtix Game](#ca5---turtix-game)
- **CA6**: [Mission Tracker](#ca6---mission-tracker)
- **CA7**: [Fantasy Football Team Manager](#ca7---fantasy-football-team-manager)

---

## Project Descriptions

### CA0 - **Basic Algorithmic Logic**

#### Concepts

- **Input/Output Handling**: Reading inputs and outputting data to the console, forming the backbone of almost any application.
- **Conditionals and Logic**: Using `if`, `else`, and conditional expressions to determine specific actions based on input values.
- **Loops**: Utilizing loops (`for`, `while`) to iterate over data or perform repetitive tasks.

#### Objective

To practice computational thinking and develop a basic understanding of control flow in a program.

#### Techniques

- **Conditional Statements**: Implementing logic to handle various conditions.
- **Iteration Structures**: Using loops to process data.
- **I/O Handling in C++**: Reading from and writing to the console.

---

### CA1 - **Day Tracking**

#### Concepts

- **Data Structures**: Using arrays or `std::map` for managing date-event pairs to store, retrieve, and manipulate date-specific data.
- **String Manipulation**: Handling text data and parsing strings to extract and store relevant information.
- **File Handling**: Introducing saving and retrieving data from files for persistent storage.
- **Algorithm Design**: Handling commands to find the "longest" or "most eventful" day by analyzing event descriptions or data.

#### Objective

To cover basic data storage, lookup, and retrieval through dynamic input, manipulating text and dates to find specific days that meet particular conditions.

#### Techniques

- **Data Structures**: Using `std::map`, `std::vector`.
- **String Handling**: Utilizing functions like `getline`, `substr`.
- **File I/O**: Reading from and writing to files.
- **Searching Algorithms**: Implementing efficient search techniques.

---

### CA2 - **Matrix Operations**

#### Concepts

- **2D Arrays**: Using two-dimensional arrays to store matrix data.
- **Matrix Transformation**: Performing operations like rotation, transposition, and reflection.
- **Linear Algebra**: Understanding how matrices work in mathematics, especially for transformations like matrix multiplication.
- **Input Parsing**: Reading matrix data from user inputs or files and converting them into arrays for computation.

#### Objective

To implement matrix-based algorithms and practice handling multi-dimensional data structures.

#### Techniques

- **Matrix Manipulation**: Using nested loops for operations.
- **Linear Algebra Concepts**: Applying mathematical principles to programming.
- **2D Arrays**: Managing multi-dimensional data.

---

### CA3 - **Schedule Planner**

#### Concepts

- **Scheduling Algorithms**: Writing a simple scheduling system to avoid conflicts in class or teacher schedules.
- **Optimization**: Implementing strategies to fit courses into schedules without conflicts.
- **File I/O**: Reading and writing data related to teacher schedules, free days, and course timings.
- **Data Structures**: Using arrays, `std::vector`, or `std::map` to store teachers, courses, and their available times.

#### Objective

To simulate a scheduling problem using optimization and data organization strategies.

#### Techniques

- **Conflict Detection Algorithms**: Implementing logic to avoid scheduling overlaps.
- **Sorting and Searching**: Organizing data efficiently.
- **File Handling**: Persisting schedule data.

---

### CA4 - **Basic String Manipulation**

#### Concepts

- **String Handling**: Manipulating strings, such as converting lowercase to uppercase.
- **Text Parsing**: Extracting data from strings and removing unnecessary characters.
- **File I/O**: Reading input from text files and writing outputs.
- **Functions**: Implementing helper functions to perform specific tasks.

#### Objective

To develop a tool for processing and manipulating text.

#### Techniques

- **String Manipulation**: Using C++ string functions.
- **File Reading/Writing**: Handling files for input and output.
- **Function Creation**: Writing reusable code blocks.

---

### CA5 - **Turtix Game**

#### Concepts

- **Object-Oriented Programming (OOP)**: Using classes to represent game entities like the turtle, stars, and enemies.
- **Graphical Libraries**: Utilizing **SFML (Simple and Fast Multimedia Library)** for graphics, window management, and event handling.
- **Event-Driven Programming**: Responding to user inputs in real-time.
- **Collision Detection**: Detecting interactions between game entities.
- **Game Design**: Implementing game logic, character movement, scoring, and enemy interaction.

#### Objective

To build a simple graphical game using object-oriented principles and game development concepts.

#### Techniques

- **OOP Principles**: Encapsulation, inheritance, and polymorphism.
- **SFML for Game Development**: Handling graphics and events.
- **Real-Time Event Handling**: Processing inputs as they occur.
- **Collision Detection Algorithms**: Implementing bounding box checks.

---

### CA6 - **Mission Tracker**

#### Concepts

- **Data Management**: Using structs or classes to represent missions that can be assigned, tracked, and completed.
- **OOP Principles**: Focusing on encapsulation and methods for managing mission states.
- **Data Structures**: Using `std::vector` or `std::map` to store multiple missions and track their status.
- **Error Handling**: Managing invalid inputs gracefully.
- **File I/O**: Persisting mission states across program executions.

#### Objective

To implement a mission management system where users can assign, update, and track tasks.

#### Techniques

- **OOP**: Designing classes with attributes and methods.
- **File I/O**: Reading and writing mission data.
- **Status Management**: Using enums or constants.
- **Error Handling in C++**: Handling exceptions and invalid inputs.

---

### CA7 - **Fantasy Football Team Manager**

#### Concepts

- **File Handling (CSV Parsing)**: Working with CSV files to store player information, team budgets, and match statistics.
- **Object-Oriented Programming**: Representing players and teams with objects that have properties like cost, points, and position.
- **Budget Management**: Implementing algorithms to manage team budgets while selecting players.
- **Polymorphism**: Managing different roles of players and adapting team behavior.
- **Dynamic User Interaction**: Handling user inputs for buying players, selecting captains, and viewing statistics.

#### Objective

To build a fantasy football management system with complex interactions between players, teams, and finances.

#### Techniques

- **OOP (Inheritance and Polymorphism)**: Designing flexible class hierarchies.
- **CSV File Parsing**: Reading and writing player data.
- **Error Handling**: Managing invalid operations.
- **Dynamic I/O Functions**: Interactive command-line interfaces.

---

## How to Run

To execute the projects:

1. **Clone the repository:**

   ```bash
   git clonehttps://github.com/tahamajs/Advanced_programming_Projects.git
   ```
2. **Navigate to the project directory:**

   ```bash
   cd advanced-programming-projects
   ```
3. **Build and run the desired project:**

   - Navigate to the specific assignment folder (e.g., `CA0`) and follow the build instructions provided in the `README.md` or `instructions.txt` within that folder.
   - Compile the code using a C++ compiler (e.g., `g++`, `clang++`):

     ```bash
     cd CA0
     g++ -std=c++11 main.cpp -o main
     ./main
     ```
   - For projects using **SFML** (e.g., CA5), ensure SFML is installed and linked during compilation.

     ```bash
     g++ -std=c++11 main.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system
     ./game
     ```
   - Replace `main.cpp` with the appropriate source files if necessary.

---

## Requirements

Ensure you have the following installed:

- **C++ Compiler**: GCC, Clang, or MSVC supporting C++11 or later.
- **SFML Library**: For projects like CA5 (Turtix Game).
- **Standard C++ Libraries**: For data structures and algorithms.
- **Additional Libraries**: As specified in individual project folders.

---

## Acknowledgements

- **Course:** Advanced Programming (APS02)
- **University:** University of Tehran
- **Instructor:** Dr Ramtin Khosravi
- **Field:** Computer Engineering

This repository was created as part of the coursework for the Advanced Programming course at the University of Tehran. **All rights to the content are reserved.**

---

## Contact

If you have any questions or suggestions, please open an issue or submit a pull request.

---

## Additional Resources

- **SFML Documentation:** [SFML Official Site](https://www.sfml-dev.org/documentation/2.5.1/)
- **C++ Reference:** [cplusplus.com](http://www.cplusplus.com/reference/) or [cppreference.com](https://en.cppreference.com/w/)

---

Feel free to explore each assignment folder for detailed code implementations, reports, and additional resources related to each project.
