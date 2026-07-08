#ifndef SORTING_H
#define SORTING_H

#include "LinkedList.h"

namespace Sorting {
    void bubbleSortByRoll(LinkedList &list, bool ascending = true);
    void bubbleSortByName(LinkedList &list, bool ascending = true);
    void selectionSortByAverage(LinkedList &list, bool descending = true);
}

#endif // SORTING_H
