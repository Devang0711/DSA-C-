#include "DynamicArrayOOP.h"
#include "MemoryTracker.h"
using namespace std;

DynamicArray::DynamicArray(int n) : size(n > 0 ? n : 0) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = 0;
    cout << "  [Constructor] allocated " << size << " ints (" << (size * sizeof(int))
         << " bytes) on the heap. Current heap usage: "
         << MemTracker::currentHeapBytes() << " bytes\n";
}

DynamicArray::DynamicArray(const DynamicArray &other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    cout << "  [Copy Constructor] made a DEEP copy of " << size
         << " ints - the two objects now own completely separate heap memory.\n";
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    if (this == &other) return *this; // guard against self-assignment

    delete[] data;                    // free our old heap memory first
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];

    cout << "  [Copy Assignment] freed old heap memory and deep-copied "
         << size << " new ints.\n";
    return *this;
}

DynamicArray::~DynamicArray() {
    delete[] data;
    cout << "  [Destructor] freed the heap memory automatically. Current heap usage: "
         << MemTracker::currentHeapBytes() << " bytes\n";
}

void DynamicArray::fillSequential(int startValue, int step) {
    for (int i = 0; i < size; i++) data[i] = startValue + i * step;
}

void DynamicArray::set(int index, int value) {
    if (index >= 0 && index < size) data[index] = value;
}

int DynamicArray::get(int index) const {
    if (index >= 0 && index < size) return data[index];
    return -1;
}

int DynamicArray::getSize() const { return size; }

void DynamicArray::display() const {
    cout << "[ ";
    for (int i = 0; i < size; i++) cout << data[i] << " ";
    cout << "]\n";
}
