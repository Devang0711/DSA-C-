# Memory Calculator - Mini Project (C++)

An interactive C++ console application built around a live "memory
calculator" that tracks every single heap allocation your program makes -
so instead of just reading about static vs dynamic memory, you can watch
the byte counts change in real time as you use it.

## How the live tracking works

`MemoryTracker.cpp` overloads the **global** `operator new` / `operator
delete` (and the array versions `new[]`/`delete[]`). Every heap allocation
anywhere in the program - whether it's your own `new int`, a `DynamicArray`
object, or even an internal allocation made by `std::vector` - passes
through these overloads, which keep a running total of:

- Current heap usage (bytes)
- Peak heap usage seen so far
- Total allocations / deallocations

This is the practical demonstration of "calculating memory" the project is
named after.

## Topics Covered

### 1. Static vs Dynamic Memory Allocation / Structure of RAM
`StaticDemo.cpp` prints real addresses and sizes for:
- **Global/Data segment**: a global variable and a `static` local variable
- **Stack**: ordinary local variables and a fixed-size local array
- **Heap**: memory obtained with `new`/`delete`

so you can see, side by side, how these regions differ and how heap usage
changes (via the live tracker) as memory is allocated and freed.

### 2. Dynamic Memory Allocation - Procedural Way
`DynamicDemo.cpp` shows the "traditional" way of managing heap memory: a
plain `new`/`delete` for a single variable, and `new[]`/`delete[]` for an
array, with no class involved - the programmer is fully responsible for
freeing what they allocate.

### 3. Dynamic Memory Allocation - OOP Way (constructor & destructor)
`DynamicArrayOOP.h/.cpp` defines a `DynamicArray` class that follows the
**Rule of Three**:
- **Constructor** allocates the heap array
- **Destructor** frees it automatically (RAII - Resource Acquisition Is
  Initialization), so you never have to remember `delete` yourself
- **Copy constructor** and **copy assignment operator** perform a deep
  copy, so two objects never accidentally share (or double-free) the same
  heap memory

`OOPMemoryDemo.cpp` drives this class interactively so you can watch the
constructor/destructor/copy messages fire, along with the live heap byte
count, and compare it directly against the procedural approach.

### 4. Vectors and its Methods / Vector vs Array
`VectorDemo.cpp` covers:
- Core `std::vector` methods: `push_back`, `pop_back`, `insert`, `erase`,
  `resize`, `clear`, `shrink_to_fit`, `size()`, `capacity()`
- A **memory calculator comparison** between a fixed-size array and a
  `std::vector` holding the same data: where each lives in memory, how
  vector capacity grows (typically doubling) as you `push_back`, and the
  small fixed overhead of the vector "handle" itself vs. its heap-allocated
  buffer

## File Structure

```
MemoryCalculator/
│
├── main.cpp             # Menu-driven entry point
├── MemoryTracker.h/.cpp  # Overloaded global new/delete - the live memory calculator
├── StaticDemo.h/.cpp     # RAM structure: Global/Data, Stack, Heap
├── DynamicDemo.h/.cpp    # Procedural-style new/delete
├── DynamicArrayOOP.h/.cpp# OOP-style DMA class (constructor/destructor/Rule of Three)
├── OOPMemoryDemo.h/.cpp  # Interactive driver for DynamicArray
├── VectorDemo.h/.cpp     # Vector methods + vector vs array memory comparison
├── Utility.h/.cpp        # Input validation & display helpers
├── README.md             # This file
└── Makefile              # Build script
```

## Build & Run

```bash
make          # builds the `memory_calculator` executable
make run      # builds (if needed) and runs the program
make clean    # removes build artifacts
```

Or compile manually:

```bash
g++ -std=c++17 -Wall -Wextra -o memory_calculator \
    main.cpp MemoryTracker.cpp StaticDemo.cpp DynamicDemo.cpp \
    DynamicArrayOOP.cpp OOPMemoryDemo.cpp VectorDemo.cpp Utility.cpp

./memory_calculator
```

## Menu Overview

```
1. Static vs Dynamic Memory: RAM Structure Demo (Code/Global/Stack/Heap)
2. Dynamic Memory Allocation - Procedural Way (new/delete)
3. Dynamic Memory Allocation - OOP Way (constructor/destructor)
4. Vectors: Methods + Vector vs Array Comparison
5. Show Live Heap Memory Report
6. Exit
```

Option 5 is available from the main menu at any time - use it to check the
current/peak heap usage after trying any of the demos above.

## Example Output (Constructor/Destructor demo)

```
-- Creating a DynamicArray object (enters scope) --
  [Constructor] allocated 5 ints (20 bytes) on the heap. Current heap usage: 20 bytes
  Contents: [ 10 15 20 25 30 ]
-- Object is about to go out of scope --
  [Destructor] freed the heap memory automatically. Current heap usage: 0 bytes
-- Object destroyed. Notice we never called delete ourselves;
   the class's destructor did it for us (RAII). --
```
