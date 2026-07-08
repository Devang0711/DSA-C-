#ifndef SEARCHING_H
#define SEARCHING_H

#include <vector>
using namespace std;

namespace Searching {
    // Requires arr to be sorted ascending. Returns index or -1 if not found.
    int binarySearch(const vector<int> &arr, int target);

    // Recursive version
    int binarySearchRecursive(const vector<int> &arr, int low, int high, int target);

    // Linear search for comparison
    int linearSearch(const vector<int> &arr, int target);
}

#endif // SEARCHING_H
