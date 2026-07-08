#ifndef SORTING_H
#define SORTING_H

#include <vector>
using namespace std;

namespace Sorting {
    // Quick Sort
    void quickSort(vector<int> &arr, int low, int high);
    int partition(vector<int> &arr, int low, int high);

    // Merge Sort
    void mergeSort(vector<int> &arr, int left, int right);
    void merge(vector<int> &arr, int left, int mid, int right);
}

#endif // SORTING_H
