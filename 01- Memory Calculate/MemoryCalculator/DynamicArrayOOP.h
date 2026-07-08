#ifndef DYNAMICARRAYOOP_H
#define DYNAMICARRAYOOP_H

#include <iostream>

// This class demonstrates the OOP way of doing Dynamic Memory Allocation:
// instead of the programmer manually calling new/delete everywhere, the
// class itself takes responsibility (RAII - Resource Acquisition Is
// Initialization). The constructor allocates, the destructor frees, and a
// copy constructor + copy assignment operator handle deep copies safely
// (the "Rule of Three").
class DynamicArray {
private:
    int* data;
    int size;

public:
    explicit DynamicArray(int n);                     // Constructor - allocates
    DynamicArray(const DynamicArray &other);          // Copy constructor - deep copy
    DynamicArray& operator=(const DynamicArray &other); // Copy assignment - deep copy
    ~DynamicArray();                                  // Destructor - deallocates

    void fillSequential(int startValue = 1, int step = 1);
    void set(int index, int value);
    int get(int index) const;
    int getSize() const;
    void display() const;
};

#endif // DYNAMICARRAYOOP_H
