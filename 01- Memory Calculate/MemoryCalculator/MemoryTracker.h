#ifndef MEMORYTRACKER_H
#define MEMORYTRACKER_H

#include <cstddef>

// This is the heart of the "Memory Calculator": every heap allocation made
// anywhere in the program (via new, new[], or indirectly through vector,
// string, etc.) is counted here because we overload the GLOBAL operator
// new/delete in MemoryTracker.cpp. That lets us report real, live heap
// usage instead of guessing.
namespace MemTracker {
    size_t currentHeapBytes();     // bytes currently allocated on the heap
    size_t peakHeapBytes();        // highest heap usage seen so far
    size_t totalAllocations();     // number of new/new[] calls since last reset
    size_t totalDeallocations();   // number of delete/delete[] calls since last reset

    void printReport();            // pretty-print the current stats
    void reset();                  // zero out the allocation/deallocation counters
}

#endif // MEMORYTRACKER_H
