#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "Sorting.h"
#include "Searching.h"
#include "Tree.h"
#include "Graph.h"
#include "Utility.h"

using namespace std;

// ============================================================
// 1. LINKED LIST MENU
// ============================================================
void linkedListMenu() {
    LinkedList list;
    bool back = false;

    while (!back) {
        Utility::printHeader("LINKED LIST");
        cout << "1. Insert at Front\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete Value\n";
        cout << "4. Search Value\n";
        cout << "5. Reverse List\n";
        cout << "6. Display List\n";
        cout << "7. Back to Main Menu\n";
        int choice = Utility::getValidInt("Enter choice: ");

        switch (choice) {
            case 1: { int v = Utility::getValidInt("Enter value: "); list.insertAtFront(v); break; }
            case 2: { int v = Utility::getValidInt("Enter value: "); list.insertAtEnd(v); break; }
            case 3: {
                int v = Utility::getValidInt("Enter value to delete: ");
                cout << (list.deleteValue(v) ? "Deleted.\n" : "Value not found.\n");
                break;
            }
            case 4: {
                int v = Utility::getValidInt("Enter value to search: ");
                cout << (list.search(v) ? "Found!\n" : "Not found.\n");
                break;
            }
            case 5: list.reverse(); cout << "List reversed.\n"; break;
            case 6: list.display(); break;
            case 7: back = true; break;
            default: cout << "Invalid choice.\n";
        }
    }
}

// ============================================================
// 2. SORTING MENU (Quick Sort & Merge Sort)
// ============================================================
void sortingMenu() {
    Utility::printHeader("SORTING (Quick Sort / Merge Sort)");
    vector<int> arr = Utility::getIntArray("Enter numbers separated by spaces: ");

    if (arr.empty()) {
        cout << "No numbers entered.\n";
        return;
    }

    cout << "\nOriginal array: ";
    Utility::displayArray(arr);

    cout << "\n1. Quick Sort\n2. Merge Sort\n";
    int choice = Utility::getValidInt("Enter choice: ");

    vector<int> result = arr;
    if (choice == 1) {
        Sorting::quickSort(result, 0, (int)result.size() - 1);
        cout << "\nSorted (Quick Sort): ";
    } else if (choice == 2) {
        Sorting::mergeSort(result, 0, (int)result.size() - 1);
        cout << "\nSorted (Merge Sort): ";
    } else {
        cout << "Invalid choice.\n";
        return;
    }
    Utility::displayArray(result);
}

// ============================================================
// 3. SEARCHING MENU (Binary Search)
// ============================================================
void searchingMenu() {
    Utility::printHeader("SEARCHING (Binary Search)");
    vector<int> arr = Utility::getIntArray("Enter SORTED numbers separated by spaces: ");

    if (arr.empty()) {
        cout << "No numbers entered.\n";
        return;
    }

    int target = Utility::getValidInt("Enter value to search for: ");
    int index = Searching::binarySearch(arr, target);

    if (index != -1) cout << "Found " << target << " at index " << index << ".\n";
    else cout << target << " not found in the array.\n";
}

// ============================================================
// 4. TREE MENU (Types of Tree + Pre/In/Post-order + Level order)
// ============================================================
void treeMenu() {
    BinarySearchTree tree;
    bool back = false;

    while (!back) {
        Utility::printHeader("TREE (Binary Search Tree)");
        cout << "1. Insert Value\n";
        cout << "2. Delete Value\n";
        cout << "3. Search Value\n";
        cout << "4. Pre-Order Traversal (Root -> Left -> Right)\n";
        cout << "5. In-Order Traversal (Left -> Root -> Right)\n";
        cout << "6. Post-Order Traversal (Left -> Right -> Root)\n";
        cout << "7. Level-Order Traversal / BFS (uses a queue)\n";
        cout << "8. Show Height\n";
        cout << "9. Back to Main Menu\n";
        int choice = Utility::getValidInt("Enter choice: ");

        switch (choice) {
            case 1: { int v = Utility::getValidInt("Enter value: "); tree.insert(v); break; }
            case 2: {
                int v = Utility::getValidInt("Enter value to delete: ");
                cout << (tree.remove(v) ? "Deleted.\n" : "Value not found.\n");
                break;
            }
            case 3: {
                int v = Utility::getValidInt("Enter value to search: ");
                cout << (tree.search(v) ? "Found!\n" : "Not found.\n");
                break;
            }
            case 4: tree.printTraversal(tree.preOrder()); break;
            case 5: tree.printTraversal(tree.inOrder()); break;
            case 6: tree.printTraversal(tree.postOrder()); break;
            case 7: tree.printTraversal(tree.levelOrder()); break;
            case 8:
                if (tree.isEmpty()) cout << "Tree is empty.\n";
                else cout << "Height: " << tree.height() << "\n";
                break;
            case 9: back = true; break;
            default: cout << "Invalid choice.\n";
        }
    }
}

// ============================================================
// 5. GRAPH MENU (BFS & DFS)
// ============================================================
void graphMenu() {
    Utility::printHeader("GRAPH SEARCHING (BFS & DFS)");

    int vertices = Utility::getValidInt("Enter number of vertices (labeled 0..n-1): ");
    if (vertices <= 0) {
        cout << "Number of vertices must be positive.\n";
        return;
    }

    Graph graph(vertices);
    int edges = Utility::getValidInt("Enter number of edges: ");

    for (int i = 0; i < edges; i++) {
        cout << "Edge " << (i + 1) << ":\n";
        int u = Utility::getValidInt("  From vertex: ");
        int v = Utility::getValidInt("  To vertex: ");
        graph.addEdge(u, v);
    }

    cout << "\nAdjacency List:\n";
    graph.display();

    int start = Utility::getValidInt("\nEnter starting vertex for traversal: ");

    cout << "\nBFS Traversal (queue-based, level by level): ";
    Utility::displayArray(graph.bfs(start));

    cout << "DFS Traversal (recursive, goes deep first): ";
    Utility::displayArray(graph.dfs(start));
}

// ============================================================
// MAIN MENU
// ============================================================
void showMainMenu() {
    Utility::printHeader("DSA FINAL PROJECT - C++");
    cout << "1. Linked List\n";
    cout << "2. Sorting (Quick Sort & Merge Sort)\n";
    cout << "3. Searching (Binary Search)\n";
    cout << "4. Tree (Types of Tree & Traversals)\n";
    cout << "5. Graph Searching (BFS & DFS)\n";
    cout << "6. Exit\n";
    Utility::printLine();
}

int main() {
    cout << "Welcome to the DSA Final Project\n";
    bool running = true;

    while (running) {
        showMainMenu();
        int choice = Utility::getValidInt("Enter your choice: ");

        switch (choice) {
            case 1: linkedListMenu(); break;
            case 2: sortingMenu(); break;
            case 3: searchingMenu(); break;
            case 4: treeMenu(); break;
            case 5: graphMenu(); break;
            case 6:
                cout << "Thank you! Goodbye.\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << "\n";
    }

    return 0;
}
