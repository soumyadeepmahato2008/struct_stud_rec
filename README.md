# strud_rec_structure
A console-based C program to add, search, and view student records using a menu-driven interface.
# Student Management System

A simple console-based Student Management System written in C. It allows users to add student records, search for a student by roll number, and view all stored records through a menu-driven interface. The program stores data in memory using a fixed-size array of structs.

---

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Project Structure](#project-structure)
- [How to Compile](#how-to-compile)
- [How to Run](#how-to-run)
- [Usage](#usage)
- [Data Structure](#data-structure)
- [Function Overview](#function-overview)
- [Example Session](#example-session)
- [Known Limitations](#known-limitations)
- [Possible Improvements](#possible-improvements)
- [License](#license)

---

## Features

- **Add Student** – Enter roll number, name, and marks for a new student.
- **Search Student** – Look up a student by roll number and display their details.
- **View All Students** – Display the details of every stored student.
- **Menu-Driven Interface** – Simple numbered menu for navigation.
- **In-Memory Storage** – Supports up to 100 students per session.

---

## Requirements

- A C compiler (GCC, Clang, or MSVC)
- Standard C library (`stdio.h`, `stdbool.h`)
- No external dependencies

---

## Project Structure

```
.
├── student_management.c   # Main source file
└── README.txt             # This file
```

---

## How to Compile

Using GCC:

```bash
gcc student_management.c -o student_management
```

Using Clang:

```bash
clang student_management.c -o student_management
```

Using MSVC (Developer Command Prompt):

```bash
cl /Fe:student_management.exe student_management.c
```

---

## How to Run

On Linux/macOS:

```bash
./student_management
```

On Windows:

```bash
student_management.exe
```

---

## Usage

When you run the program, the following menu is displayed:

```
1. Add student
2. View student
3. View all students
4. Exit
Enter your choice:
```

### 1. Add Student

Prompts for:

- **Roll number** (integer)
- **Name** (string, can contain spaces)
- **Marks** (integer)

The record is appended to the array and the student count is incremented.

### 2. View Student

Prompts for a roll number and searches the stored records. If a matching record is found, its details are printed. Otherwise, a "Match Not Found!" message is shown.

### 3. View All Students

Loops through all stored records and prints each student's details.

### 4. Exit

Prints a thank-you message and terminates the program.

Any other input prints "Invalid choice! Try Again!" and re-displays the menu.

---

## Data Structure

Each student record is defined as:

```c
typedef struct {
    int roll_no;
    char name[50];
    int marks;
} student;
```

Records are stored in a global array:

```c
student stud[100];
int n = 0;   // number of students currently stored
```

- `stud` holds up to **100** student records.
- `n` tracks how many records have been added.

---

## Function Overview

| Function | Purpose |
|----------|---------|
| `addstud()` | Reads roll number, name, and marks from the user and stores them in `stud[n]`, then increments `n`. |
| `viewstud()` | Asks for a roll number, loops through all records, and prints any match. |
| `viewall()` | Loops through all records and prints each student's details. |
| `main()` | Displays the menu in a loop and dispatches to the appropriate function based on user input. |

---

## Example Session

```
1. Add student
2. View student
3. View all students
4. Exit
Enter your choice: 1
Enter roll no: 101
Enter name: Alice
Enter marks: 92

Student added successfully!

1. Add student
2. View student
3. View all students
4. Exit
Enter your choice: 2
Enter the roll no: 101

Match found!
Roll No: 101
Name: Alice
Marks: 92

1. Add student
2. View student
3. View all students
4. Exit
Enter your choice: 4

Thank you!
```

---

## Known Limitations

- **No persistence** – Data is lost when the program exits (no file storage).
- **Fixed capacity** – Maximum of 100 students.
- **Search bug** – `viewstud()` prints "Match Not Found!" for every non-matching record rather than once at the end. If multiple students exist, this message will appear repeatedly even when a match is found later in the list.
- **Display bug** – `viewall()` labels every student as `n+1` instead of `i+1`, so all entries show the same (incorrect) student number.
- **No input validation** – Duplicate roll numbers, non-numeric input, or overly long names are not handled.

---

## Possible Improvements

- Fix the search and display bugs mentioned above.
- Add file I/O to persist records between runs.
- Add **update** and **delete** operations.
- Use `malloc`/`realloc` (dynamic memory) instead of a fixed-size array.
- Validate input (duplicate roll numbers, numeric checks, name length).
- Add sorting (e.g., by roll number or marks).
- Modularize the code into multiple files (`student.c`, `student.h`, `main.c`).

---

## License

This project is open source and available under the MIT License. Feel free to use, modify, and distribute it.
