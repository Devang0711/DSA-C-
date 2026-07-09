/*
    ============================================================
     MEMORY CALCULATOR (Simple Version)
    ============================================================
    Pick a data type, tell it how many elements you need (array
    size), and it calculates the total memory required - in
    bytes, KB, and MB. It can also show you a real example by
    actually allocating that memory on the heap with new[].

    Build:  g++ -std=c++17 -Wall -Wextra -o memory_calculator MemoryCalculator.cpp
    Run  :  ./memory_calculator
*/

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// ------------------------------------------------------------
// Reads a validated integer from the user (re-asks on bad input)
// ------------------------------------------------------------
long long getValidInt(const string &prompt) {
    long long value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.eof()) {
            cout << "\nNo more input available. Exiting.\n";
            exit(0);
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid whole number.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// ------------------------------------------------------------
// Returns sizeof() for the chosen data type, and fills in its name
// ------------------------------------------------------------
size_t getTypeSize(int choice, string &typeName) {
    switch (choice) {
        case 1: typeName = "char";        return sizeof(char);
        case 2: typeName = "short";       return sizeof(short);
        case 3: typeName = "int";         return sizeof(int);
        case 4: typeName = "long";        return sizeof(long);
        case 5: typeName = "long long";   return sizeof(long long);
        case 6: typeName = "float";       return sizeof(float);
        case 7: typeName = "double";      return sizeof(double);
        case 8: typeName = "bool";        return sizeof(bool);
        default: typeName = "";           return 0;
    }
}

// ------------------------------------------------------------
// Pretty-prints a byte count as bytes / KB / MB
// ------------------------------------------------------------
void printMemoryBreakdown(long long totalBytes) {
    double kb = totalBytes / 1024.0;
    double mb = kb / 1024.0;

    cout << fixed << setprecision(4);
    cout << "  Total memory : " << totalBytes << " bytes\n";
    cout << "               = " << kb << " KB\n";
    cout << "               = " << mb << " MB\n";
    cout.unsetf(ios::fixed);
}

void showTypeMenu() {
    cout << "\nChoose a data type:\n";
    cout << "  1. char        2. short       3. int         4. long\n";
    cout << "  5. long long   6. float       7. double      8. bool\n";
}

// ------------------------------------------------------------
// Option 1: pure calculation using sizeof() - no memory is
// actually allocated, just the arithmetic.
// ------------------------------------------------------------
void calculateMemory() {
    cout << "\n===== Calculate Memory (sizeof only) =====\n";
    showTypeMenu();
    int typeChoice = (int)getValidInt("Enter your choice (1-8): ");

    string typeName;
    size_t elementSize = getTypeSize(typeChoice, typeName);
    if (elementSize == 0) {
        cout << "Invalid data type choice.\n";
        return;
    }

    long long count = getValidInt("How many elements (array size)? ");
    if (count <= 0) {
        cout << "Count must be positive.\n";
        return;
    }

    long long totalBytes = (long long)elementSize * count;

    cout << "\n-- Result --\n";
    cout << "  Data type    : " << typeName << " (each element = " << elementSize << " bytes)\n";
    cout << "  Element count: " << count << "\n";
    printMemoryBreakdown(totalBytes);
}

// ------------------------------------------------------------
// Option 2: actually allocate the array on the heap with new[]
// and confirm the calculated size matches reality.
// ------------------------------------------------------------
void allocateAndVerify() {
    cout << "\n===== Allocate on Heap & Verify =====\n";
    showTypeMenu();
    int typeChoice = (int)getValidInt("Enter your choice (1-8): ");

    long long count = getValidInt("How many elements (array size)? ");
    if (count <= 0) {
        cout << "Count must be positive.\n";
        return;
    }

    string typeName;
    switch (typeChoice) {
        case 1: { char* arr = new char[count]; typeName = "char";
                  cout << "  Allocated at address " << (void*)arr << "\n";
                  cout << "  sizeof(char) * " << count << " = " << (sizeof(char) * count) << " bytes\n";
                  delete[] arr; break; }
        case 2: { short* arr = new short[count]; typeName = "short";
                  cout << "  Allocated at address " << (void*)arr << "\n";
                  cout << "  sizeof(short) * " << count << " = " << (sizeof(short) * count) << " bytes\n";
                  delete[] arr; break; }
        case 3: { int* arr = new int[count]; typeName = "int";
                  cout << "  Allocated at address " << (void*)arr << "\n";
                  cout << "  sizeof(int) * " << count << " = " << (sizeof(int) * count) << " bytes\n";
                  delete[] arr; break; }
        case 4: { long* arr = new long[count]; typeName = "long";
                  cout << "  Allocated at address " << (void*)arr << "\n";
                  cout << "  sizeof(long) * " << count << " = " << (sizeof(long) * count) << " bytes\n";
                  delete[] arr; break; }
        case 5: { long long* arr = new long long[count]; typeName = "long long";
                  cout << "  Allocated at address " << (void*)arr << "\n";
                  cout << "  sizeof(long long) * " << count << " = " << (sizeof(long long) * count) << " bytes\n";
                  delete[] arr; break; }
        case 6: { float* arr = new float[count]; typeName = "float";
                  cout << "  Allocated at address " << (void*)arr << "\n";
                  cout << "  sizeof(float) * " << count << " = " << (sizeof(float) * count) << " bytes\n";
                  delete[] arr; break; }
        case 7: { double* arr = new double[count]; typeName = "double";
                  cout << "  Allocated at address " << (void*)arr << "\n";
                  cout << "  sizeof(double) * " << count << " = " << (sizeof(double) * count) << " bytes\n";
                  delete[] arr; break; }
        case 8: { bool* arr = new bool[count]; typeName = "bool";
                  cout << "  Allocated at address " << (void*)arr << "\n";
                  cout << "  sizeof(bool) * " << count << " = " << (sizeof(bool) * count) << " bytes\n";
                  delete[] arr; break; }
        default:
            cout << "Invalid data type choice.\n";
            return;
    }

    cout << "  (Memory has been freed with delete[] after verifying.)\n";
}

void showMainMenu() {
    cout << "\n========================================\n";
    cout << "         MEMORY CALCULATOR\n";
    cout << "========================================\n";
    cout << "1. Calculate memory for a data type + count\n";
    cout << "2. Allocate on heap & verify actual size\n";
    cout << "3. Exit\n";
    cout << "----------------------------------------\n";
}

int main() {
    cout << "Welcome to the Memory Calculator!\n";
    bool running = true;

    while (running) {
        showMainMenu();
        int choice = (int)getValidInt("Enter your choice: ");

        switch (choice) {
            case 1: calculateMemory(); break;
            case 2: allocateAndVerify(); break;
            case 3:
                cout << "Thank you! Goodbye.\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
