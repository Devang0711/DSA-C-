# DSA Final Project (C++)

A menu-driven C++ console application built to demonstrate the core Data
Structures & Algorithms topics from the course: **Linked List, Binary Search,
Quick Sort & Merge Sort, Tree Data Structure with all three traversals, and
Graph Searching with BFS & DFS.**

## Topics Covered

### 1. Linked List
Custom singly linked list supporting insert (front/end), delete, search,
reverse, and display.

### 2. Sorting — Quick Sort & Merge Sort
- **Quick Sort**: divide-and-conquer, partitions around a pivot, average
  O(n log n), worst case O(n²).
- **Merge Sort**: divide-and-conquer, splits the array, sorts each half,
  and merges — guaranteed O(n log n) in all cases.

### 3. Searching — Binary Search
Classic binary search on a sorted array, O(log n). A recursive version and a
plain linear search are also included in `Searching.cpp` for comparison.

### 4. Tree Data Structure

**Types of Tree** (conceptually, a Binary Search Tree is implemented as the
practical example — the same node/traversal logic generalizes to plain
binary trees, AVL trees, heaps, etc., which only add extra balancing or
ordering rules on top of this structure):
- General Tree — each node can have any number of children.
- Binary Tree — each node has at most 2 children.
- Binary Search Tree (BST) — implemented here: left subtree < node < right subtree.
- Balanced trees (AVL, Red-Black) — BSTs with self-balancing rules.
- Heap — a complete binary tree with a min/max ordering property.

**Types of Tree Traversal** (all implemented in `Tree.cpp`):
1. **Pre-Order** (Root → Left → Right) — used to copy/serialize a tree.
2. **In-Order** (Left → Root → Right) — visits BST nodes in sorted order.
3. **Post-Order** (Left → Right → Root) — used to safely delete a tree.
4. **Level-Order** (Breadth-First, using a queue) — included as a bonus,
   since it's the tree analogue of BFS.

### 5. Searching Algorithm — BFS & DFS (on a Graph)
Implemented in `Graph.cpp` using an adjacency list:
- **Breadth-First Search (BFS)**: explores neighbor-by-neighbor level by
  level using a queue. Good for shortest path in an unweighted graph.
- **Depth-First Search (DFS)**: explores as far as possible down one path
  before backtracking, implemented recursively with a visited array.

## File Structure

```
DSA_FinalProject/
│
├── main.cpp          # Menu-driven entry point demonstrating every topic
├── LinkedList.h/.cpp  # Singly linked list
├── Sorting.h/.cpp     # Quick Sort & Merge Sort
├── Searching.h/.cpp   # Binary Search (+ linear search for comparison)
├── Tree.h/.cpp        # Binary Search Tree: insert/delete/search + all traversals
├── Graph.h/.cpp       # Adjacency-list graph: BFS & DFS
├── Utility.h/.cpp     # Input validation & display helpers
├── README.md          # This file
└── Makefile           # Build script
```

## Build & Run

```bash
make          # builds the `dsa_final_project` executable
make run      # builds (if needed) and runs the program
make clean    # removes build artifacts
```

Or compile manually:

```bash
g++ -std=c++17 -Wall -Wextra -o dsa_final_project \
    main.cpp LinkedList.cpp Sorting.cpp Searching.cpp Tree.cpp Graph.cpp Utility.cpp

./dsa_final_project
```

## Menu Overview

```
1. Linked List
2. Sorting (Quick Sort & Merge Sort)
3. Searching (Binary Search)
4. Tree (Types of Tree & Traversals)
5. Graph Searching (BFS & DFS)
6. Exit
```

Each section has its own sub-menu so you can try every operation
interactively — insert/delete/search on the list or tree, sort or search
an array you type in, or build a small graph and watch BFS/DFS visit its
vertices in order.

## Example: Tree Traversal Output

Inserting `50, 30, 70, 20, 40, 60, 80` into the BST gives:

```
Pre-Order   : [ 50 30 20 40 70 60 80 ]
In-Order    : [ 20 30 40 50 60 70 80 ]   <- always sorted for a BST
Post-Order  : [ 20 40 30 60 80 70 50 ]
Level-Order : [ 50 30 70 20 40 60 80 ]
```

## Example: Graph BFS/DFS Output

For a graph with edges `0-1, 0-2, 1-3, 1-4, 2-4`, starting from vertex `0`:

```
BFS: [ 0 1 2 3 4 ]   <- visits level by level
DFS: [ 0 1 3 4 2 ]   <- goes deep down one branch first
```
