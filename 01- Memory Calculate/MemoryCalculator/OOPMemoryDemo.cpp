#include "OOPMemoryDemo.h"
#include "DynamicArrayOOP.h"
#include "MemoryTracker.h"
#include "Utility.h"
#include <iostream>
using namespace std;

namespace OOPMemoryDemo {

    static void demoConstructorDestructor() {
        cout << "\n-- Creating a DynamicArray object (enters scope) --\n";
        {
            DynamicArray arr(5);        // constructor runs here
            arr.fillSequential(10, 5);  // 10, 15, 20, 25, 30
            cout << "  Contents: ";
            arr.display();
            cout << "-- Object is about to go out of scope --\n";
        } // destructor runs automatically here - no manual delete needed!
        cout << "-- Object destroyed. Notice we never called delete ourselves;\n"
                "   the class's destructor did it for us (RAII). --\n";
    }

    static void demoCopySemantics() {
        cout << "\n-- Copy Constructor & Copy Assignment demo --\n";
        DynamicArray original(4);
        original.fillSequential(1, 1); // 1,2,3,4
        cout << "  original: "; original.display();

        cout << "\n  Making a copy with the copy constructor...\n";
        DynamicArray copy(original); // calls copy constructor
        copy.set(0, 999);
        cout << "  original: "; original.display();
        cout << "  copy    : "; copy.display();
        cout << "  (Changing 'copy' did NOT affect 'original' - they own separate heap memory.)\n";

        cout << "\n  Now testing copy assignment (=) ...\n";
        DynamicArray another(2);
        another.fillSequential(100, 1);
        cout << "  another (before) : "; another.display();
        another = original; // calls copy assignment operator
        cout << "  another (after)  : "; another.display();
        cout << "  (another's old heap memory was freed, then a fresh deep copy was made.)\n";

        cout << "\n-- All three DynamicArray objects (original, copy, another) will now\n"
                "   be destroyed automatically as this function returns. --\n";
    }

    void run() {
        bool back = false;
        while (!back) {
            Utility::printHeader("DYNAMIC MEMORY ALLOCATION - OOP Way");
            cout << "1. Constructor / Destructor demo (RAII)\n";
            cout << "2. Copy Constructor / Copy Assignment demo\n";
            cout << "3. Show live heap report\n";
            cout << "4. Back to Main Menu\n";
            int choice = Utility::getValidInt("Enter choice: ");

            switch (choice) {
                case 1: demoConstructorDestructor(); break;
                case 2: demoCopySemantics(); break;
                case 3: MemTracker::printReport(); break;
                case 4: back = true; break;
                default: cout << "Invalid choice.\n";
            }
        }
    }
}
