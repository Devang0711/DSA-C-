#ifndef SEARCHING_H
#define SEARCHING_H

#include "LinkedList.h"

namespace Searching {
    // Linear search directly on the linked list
    Node* linearSearchByRoll(const LinkedList &list, int roll);
    Node* linearSearchByName(const LinkedList &list, const string &name);

    // Binary search requires a sorted array; returns index or -1
    int binarySearchByRoll(Student arr[], int n, int roll);
}

#endif // SEARCHING_H
