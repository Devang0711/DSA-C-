#include "MemoryTracker.h"
#include <cstdlib>
#include <new>
#include <iostream>

// ------------------------------------------------------------------
// Internal counters (file-local, hidden from the rest of the program)
// ------------------------------------------------------------------
namespace {
    size_t g_currentBytes = 0;
    size_t g_peakBytes = 0;
    size_t g_totalAllocations = 0;
    size_t g_totalDeallocations = 0;

    // We allocate a few extra bytes before the pointer we hand back, and
    // store the requested size there. That way, whether the caller uses
    // delete or delete[], we always know exactly how many bytes to
    // subtract when freeing - no separate bookkeeping table needed.
    inline void* trackedAlloc(std::size_t size) {
        std::size_t totalSize = size + sizeof(std::size_t);
        void* raw = std::malloc(totalSize);
        if (raw == nullptr) throw std::bad_alloc();

        *reinterpret_cast<std::size_t*>(raw) = size;

        g_currentBytes += size;
        g_totalAllocations++;
        if (g_currentBytes > g_peakBytes) g_peakBytes = g_currentBytes;

        return reinterpret_cast<char*>(raw) + sizeof(std::size_t);
    }

    inline void trackedFree(void* ptr) noexcept {
        if (ptr == nullptr) return;

        char* raw = reinterpret_cast<char*>(ptr) - sizeof(std::size_t);
        std::size_t size = *reinterpret_cast<std::size_t*>(raw);

        g_currentBytes -= size;
        g_totalDeallocations++;

        std::free(raw);
    }
}

// ------------------------------------------------------------------
// Public reporting API
// ------------------------------------------------------------------
namespace MemTracker {
    size_t currentHeapBytes() { return g_currentBytes; }
    size_t peakHeapBytes() { return g_peakBytes; }
    size_t totalAllocations() { return g_totalAllocations; }
    size_t totalDeallocations() { return g_totalDeallocations; }

    void reset() {
        g_peakBytes = g_currentBytes;
        g_totalAllocations = 0;
        g_totalDeallocations = 0;
    }

    void printReport() {
        std::cout << "\n----------- Live Heap Memory Report -----------\n";
        std::cout << "Current heap usage   : " << g_currentBytes << " bytes\n";
        std::cout << "Peak heap usage       : " << g_peakBytes << " bytes\n";
        std::cout << "Allocations so far    : " << g_totalAllocations << "\n";
        std::cout << "Deallocations so far  : " << g_totalDeallocations << "\n";
        std::cout << "------------------------------------------------\n";
    }
}

// ------------------------------------------------------------------
// Global operator overloads - this is what makes tracking possible.
// EVERY `new` and `delete` in the whole program routes through here.
// ------------------------------------------------------------------
void* operator new(std::size_t size) {
    return trackedAlloc(size);
}

void operator delete(void* ptr) noexcept {
    trackedFree(ptr);
}

void operator delete(void* ptr, std::size_t) noexcept {
    trackedFree(ptr);
}

void* operator new[](std::size_t size) {
    return trackedAlloc(size);
}

void operator delete[](void* ptr) noexcept {
    trackedFree(ptr);
}

void operator delete[](void* ptr, std::size_t) noexcept {
    trackedFree(ptr);
}
