#include <iostream>
#include "MemoryTracker.h"
#include "StaticDemo.h"
#include "DynamicDemo.h"
#include "OOPMemoryDemo.h"
#include "VectorDemo.h"
#include "Utility.h"
using namespace std;

void showMainMenu() {
    Utility::printHeader("MEMORY CALCULATOR - Mini Project");
    cout << "1. Static vs Dynamic Memory: RAM Structure Demo (Code/Global/Stack/Heap)\n";
    cout << "2. Dynamic Memory Allocation - Procedural Way (new/delete)\n";
    cout << "3. Dynamic Memory Allocation - OOP Way (constructor/destructor)\n";
    cout << "4. Vectors: Methods + Vector vs Array Comparison\n";
    cout << "5. Show Live Heap Memory Report\n";
    cout << "6. Exit\n";
    Utility::printLine();
}

int main() {
    cout << "Welcome to the Memory Calculator Mini Project\n";
    cout << "(Every new/delete anywhere in this program is being tracked live!)\n";

    bool running = true;
    while (running) {
        showMainMenu();
        int choice = Utility::getValidInt("Enter your choice: ");

        switch (choice) {
            case 1: StaticDemo::run(); break;
            case 2: DynamicDemo::run(); break;
            case 3: OOPMemoryDemo::run(); break;
            case 4: VectorDemo::run(); break;
            case 5: MemTracker::printReport(); break;
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
