#include "VectorDemo.h"
#include "MemoryTracker.h"
#include "Utility.h"
#include <iostream>
#include <vector>
using namespace std;

namespace VectorDemo {

    static void printStatus(const vector<int> &v) {
        cout << "  size=" << v.size() << ", capacity=" << v.capacity()
             << ", heap bytes used by elements ~ " << (v.capacity() * sizeof(int)) << "\n";
        cout << "  contents: [ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }

    void interactiveMenu() {
        vector<int> v;
        bool back = false;

        while (!back) {
            Utility::printHeader("VECTOR METHODS");
            cout << "1. push_back(value)\n";
            cout << "2. pop_back()\n";
            cout << "3. insert(index, value)\n";
            cout << "4. erase(index)\n";
            cout << "5. resize(newSize)\n";
            cout << "6. clear()\n";
            cout << "7. shrink_to_fit()\n";
            cout << "8. Show size/capacity/contents\n";
            cout << "9. Back to Vector Menu\n";
            int choice = Utility::getValidInt("Enter choice: ");

            switch (choice) {
                case 1: {
                    int val = Utility::getValidInt("  Value to push_back: ");
                    size_t before = MemTracker::currentHeapBytes();
                    v.push_back(val);
                    cout << "  Heap usage: " << before << " -> " << MemTracker::currentHeapBytes()
                         << " bytes (capacity may have doubled if it ran out of room)\n";
                    printStatus(v);
                    break;
                }
                case 2:
                    if (v.empty()) cout << "  Vector is already empty.\n";
                    else { v.pop_back(); cout << "  Removed last element.\n"; printStatus(v); }
                    break;
                case 3: {
                    int idx = Utility::getValidInt("  Index to insert at: ");
                    int val = Utility::getValidInt("  Value to insert: ");
                    if (idx < 0 || idx > (int)v.size()) { cout << "  Index out of range.\n"; break; }
                    v.insert(v.begin() + idx, val);
                    printStatus(v);
                    break;
                }
                case 4: {
                    int idx = Utility::getValidInt("  Index to erase: ");
                    if (idx < 0 || idx >= (int)v.size()) { cout << "  Index out of range.\n"; break; }
                    v.erase(v.begin() + idx);
                    printStatus(v);
                    break;
                }
                case 5: {
                    int newSize = Utility::getValidInt("  New size: ");
                    if (newSize < 0) { cout << "  Size cannot be negative.\n"; break; }
                    v.resize(newSize);
                    printStatus(v);
                    break;
                }
                case 6:
                    v.clear();
                    cout << "  Cleared all elements (size is now 0, but capacity is unchanged - "
                            "clear() does not free the underlying memory).\n";
                    printStatus(v);
                    break;
                case 7:
                    v.shrink_to_fit();
                    cout << "  Asked the vector to release unused capacity.\n";
                    printStatus(v);
                    break;
                case 8:
                    printStatus(v);
                    break;
                case 9: back = true; break;
                default: cout << "Invalid choice.\n";
            }
        }
    }

    void compareVectorVsArray() {
        Utility::printHeader("MEMORY CALCULATOR: Vector vs Array");
        int n = Utility::getValidInt("Enter number of elements to compare: ");
        if (n <= 0) { cout << "Must be positive.\n"; return; }

        cout << "\n-- Static/Stack Array --\n";
        cout << "  A fixed-size array declared like `int arr[" << n << "]` lives on the stack.\n";
        cout << "  Its total size is fixed at COMPILE time: " << (n * sizeof(int)) << " bytes.\n";
        cout << "  It cannot grow; if you need more elements, you must create a new, bigger array.\n";

        cout << "\n-- std::vector --\n";
        size_t before = MemTracker::currentHeapBytes();
        vector<int> v;
        for (int i = 0; i < n; i++) v.push_back(i);
        size_t after = MemTracker::currentHeapBytes();

        cout << "  A vector stores its elements on the HEAP and can grow at RUN time.\n";
        cout << "  After pushing " << n << " elements:\n";
        cout << "    size=" << v.size() << ", capacity=" << v.capacity() << "\n";
        cout << "    heap bytes actually reserved: " << (v.capacity() * sizeof(int))
             << " (>= " << (n * sizeof(int)) << " needed, because vectors over-allocate to amortize growth)\n";
        cout << "    heap usage went from " << before << " to " << after << " bytes\n";
        cout << "    sizeof(vector<int>) object itself (just the 'handle'): " << sizeof(v) << " bytes"
                " (pointer + size + capacity - the real data lives separately on the heap)\n";

        cout << "\n-- Key Differences --\n";
        cout << "  1. Array size is fixed at compile time; vector can grow/shrink at run time.\n";
        cout << "  2. Array lives on the stack (usually); vector's data lives on the heap.\n";
        cout << "  3. Array has zero extra overhead; vector has a small fixed overhead\n";
        cout << "     (pointer + size + capacity) plus possibly unused reserved capacity.\n";
        cout << "  4. Vector provides safe methods (push_back, insert, erase, at, size, etc.);\n";
        cout << "     a raw array only supports indexing and sizeof.\n";
    }

    void run() {
        bool back = false;
        while (!back) {
            Utility::printHeader("VECTORS");
            cout << "1. Try Vector Methods Interactively\n";
            cout << "2. Compare Vector vs Array (Memory Calculator)\n";
            cout << "3. Back to Main Menu\n";
            int choice = Utility::getValidInt("Enter choice: ");

            switch (choice) {
                case 1: interactiveMenu(); break;
                case 2: compareVectorVsArray(); break;
                case 3: back = true; break;
                default: cout << "Invalid choice.\n";
            }
        }
    }
}
