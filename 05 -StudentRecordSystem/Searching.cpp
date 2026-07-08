#include "Searching.h"

namespace Searching {

    Node* linearSearchByRoll(const LinkedList &list, int roll) {
        return list.findByRoll(roll);
    }

    Node* linearSearchByName(const LinkedList &list, const string &name) {
        return list.findByName(name);
    }

    // Requires arr to be sorted by roll number in ascending order
    int binarySearchByRoll(Student arr[], int n, int roll) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].getRollNo() == roll) return mid;
            else if (arr[mid].getRollNo() < roll) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
}
