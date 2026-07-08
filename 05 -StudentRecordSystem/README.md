# Student Record Management System

A menu-driven C++ console application for managing student records using a
custom singly linked list. The project demonstrates core data structures and
algorithms (linked lists, searching, sorting, statistics) using a clean,
modular file structure.

## Features

- **Add, Display, Delete** student records (Roll No, Name, marks for 5 subjects)
- **Automatic result calculation**: total, average, and grade (A/B/C/D/F)
- **Searching**
  - Linear search by roll number
  - Linear search by name
  - Binary search by roll number (on a sorted array, used internally)
- **Sorting** (in-place on the linked list)
  - Bubble sort by roll number
  - Bubble sort by name
  - Selection sort by average marks
- **Statistics**
  - Class average, top/lowest student, pass count, subject-wise averages
- **Persistence**: save/load all records to/from a text file (`students.dat`)
- **Input validation** for all user input (integers, floats, non-empty names)

## File Structure

```
StudentRecordSystem/
│
├── main.cpp          # Menu-driven entry point tying all modules together
├── Student.h/.cpp     # Student class: data + result calculation
├── LinkedList.h/.cpp  # Singly linked list storing Student records
├── Searching.h/.cpp   # Linear & binary search algorithms
├── Sorting.h/.cpp     # Bubble sort & selection sort on the linked list
├── Statistics.h/.cpp  # Class-wide statistics and reporting
├── Utility.h/.cpp     # Input validation, display helpers, file I/O
├── README.md          # This file
├── Report.pdf         # Project report / documentation
└── Makefile           # Build script
```

## Build & Run

### Using the Makefile (Linux/macOS/WSL/MinGW)

```bash
make          # builds the `student_record_system` executable
make run      # builds (if needed) and runs the program
make clean    # removes build artifacts and the saved data file
```

### Manual compilation

```bash
g++ -std=c++17 -Wall -Wextra -o student_record_system \
    main.cpp Student.cpp LinkedList.cpp Searching.cpp Sorting.cpp Statistics.cpp Utility.cpp

./student_record_system
```

## Data File Format

Records are saved to `students.dat` in a simple pipe/comma-delimited format:

```
rollNo|name|mark1,mark2,mark3,mark4,mark5
```

This file is created automatically the first time you choose **Save Data to
File**, and can be reloaded anytime with **Load Data from File**.

## Menu Overview

```
1. Add Student
2. Display All Students
3. Search Student
4. Sort Students
5. Delete Student
6. Show Statistics
7. Save Data to File
8. Load Data from File
9. Exit
```

## Notes

- Marks are validated to be within 0–100 for each of the 5 subjects.
- Grading scale: A (>=90), B (>=75), C (>=60), D (>=40), F (<40), based on average.
- Sorting works directly on the linked list by swapping node contents, so no
  extra array conversion is needed for bubble/selection sort.
- Binary search is demonstrated on a sorted array to show the classic
  algorithm, since binary search requires random access which a linked list
  doesn't provide efficiently.
