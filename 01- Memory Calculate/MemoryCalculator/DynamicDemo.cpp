#include "DynamicDemo.h"
#include "MemoryTracker.h"
#include "Utility.h"
#include <iostream>
using namespace std;

namespace DynamicDemo {

    // Procedural DMA: we manage the pointer ourselves, with no class or
    // constructor/destructor to help us. It's entirely on the programmer
    // to remember to call delete.
    void demoSingleVariable() {
        cout << "\n-- Procedural DMA: single variable --\n";
        size_t before = MemTracker::currentHeapBytes();

        int* ptr = new int;   // allocate one int on the heap
        *ptr = 42;
        cout << "  Allocated 1 int on heap at address " << ptr
             << ", value = " << *ptr << "\n";
        cout << "  Heap usage: " << before << " -> " << MemTracker::currentHeapBytes() << " bytes\n";

        delete ptr;            // must free it manually
        ptr = nullptr;          // good practice: avoid a dangling pointer
        cout << "  After delete, heap usage back to " << MemTracker::currentHeapBytes() << " bytes\n";
    }

    void demoDynamicArray() {
        cout << "\n-- Procedural DMA: dynamic array --\n";
        int n = Utility::getValidInt("  How many integers should the array hold? ");
        if (n <= 0) {
            cout << "  Size must be positive.\n";
            return;
        }

        size_t before = MemTracker::currentHeapBytes();
        int* arr = new int[n];  // allocate n ints on the heap

        for (int i = 0; i < n; i++) arr[i] = (i + 1) * 10;

        cout << "  Allocated array of " << n << " ints (" << (n * sizeof(int)) << " bytes) at address " << arr << "\n";
        cout << "  Contents: ";
        Utility::displayIntArray(arr, n);
        cout << "  Heap usage: " << before << " -> " << MemTracker::currentHeapBytes() << " bytes\n";

        delete[] arr;            // must use delete[] for arrays, not delete
        arr = nullptr;
        cout << "  After delete[], heap usage back to " << MemTracker::currentHeapBytes() << " bytes\n";
    }

    void run() {
        bool back = false;
        while (!back) {
            Utility::printHeader("DYNAMIC MEMORY ALLOCATION - Procedural Way");
            cout << "1. Allocate/free a single variable (new/delete)\n";
            cout << "2. Allocate/free a dynamic array (new[]/delete[])\n";
            cout << "3. Show live heap report\n";
            cout << "4. Back to Main Menu\n";
            int choice = Utility::getValidInt("Enter choice: ");

            switch (choice) {
                case 1: demoSingleVariable(); break;
                case 2: demoDynamicArray(); break;
                case 3: MemTracker::printReport(); break;
                case 4: back = true; break;
                default: cout << "Invalid choice.\n";
            }
        }
    }
}
