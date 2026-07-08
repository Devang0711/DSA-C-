#include "StaticDemo.h"
#include "MemoryTracker.h"
#include <iostream>
using namespace std;

// Global variable: allocated once when the program starts, lives in the
// Global/Data segment of RAM for the entire program lifetime.
int globalCounter = 100;

namespace StaticDemo {

    void run() {
        cout << "\n===== RAM Structure: Code / Global / Stack / Heap =====\n";
        cout << "A running program's memory is typically divided into:\n";
        cout << "  1. Code (Text) segment - the compiled instructions themselves\n";
        cout << "  2. Global/Data segment  - global & static variables (fixed size, exists for the program's life)\n";
        cout << "  3. Stack               - local variables & function calls (grows/shrinks automatically)\n";
        cout << "  4. Heap                - memory you request manually with new/delete (grows/shrinks on demand)\n\n";

        // static local variable: also lives in the Global/Data segment, but
        // its scope is limited to this function; it keeps its value between calls.
        static int staticCallCount = 0;
        staticCallCount++;

        // Stack variables: created fresh every time run() is called, destroyed
        // automatically when the function returns.
        int stackLocal = 25;
        double stackDouble = 3.14159;
        int stackArray[5] = {1, 2, 3, 4, 5};

        cout << "-- Global / Static storage (Data segment) --\n";
        cout << "  globalCounter     : value=" << globalCounter
             << ", address=" << &globalCounter << ", size=" << sizeof(globalCounter) << " bytes\n";
        cout << "  staticCallCount   : value=" << staticCallCount
             << ", address=" << &staticCallCount << ", size=" << sizeof(staticCallCount) << " bytes"
             << "  (this function has now run " << staticCallCount << " time(s))\n";

        cout << "\n-- Stack (local variables, freed automatically) --\n";
        cout << "  stackLocal        : value=" << stackLocal
             << ", address=" << &stackLocal << ", size=" << sizeof(stackLocal) << " bytes\n";
        cout << "  stackDouble       : value=" << stackDouble
             << ", address=" << &stackDouble << ", size=" << sizeof(stackDouble) << " bytes\n";
        cout << "  stackArray[5]     : address=" << stackArray
             << ", total size=" << sizeof(stackArray) << " bytes (fixed at compile time)\n";

        cout << "\n-- Heap (manual new/delete, freed only when you say so) --\n";
        size_t before = MemTracker::currentHeapBytes();
        int* heapVar = new int(75);
        int* heapArray = new int[5]{10, 20, 30, 40, 50};
        size_t after = MemTracker::currentHeapBytes();

        cout << "  heapVar (new int) : value=" << *heapVar << ", address=" << heapVar
             << ", size=" << sizeof(int) << " bytes\n";
        cout << "  heapArray (new[]) : address=" << heapArray
             << ", total size=" << (5 * sizeof(int)) << " bytes\n";
        cout << "  Heap usage went from " << before << " to " << after
             << " bytes after these two allocations.\n";

        delete heapVar;
        delete[] heapArray;
        cout << "  Heap usage back to " << MemTracker::currentHeapBytes()
             << " bytes after delete/delete[].\n";

        cout << "\nKey takeaway: stack addresses (stackLocal, stackArray) and heap addresses\n"
                "(heapVar, heapArray) are typically far apart in memory, and the stack\n"
                "variables disappear automatically the moment this function returns -\n"
                "the heap ones would leak if we forgot to delete them.\n";
    }
}
