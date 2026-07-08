#include "Searching.h"

namespace Searching {

    int binarySearch(const vector<int> &arr, int target) {
        int low = 0, high = (int)arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    int binarySearchRecursive(const vector<int> &arr, int low, int high, int target) {
        if (low > high) return -1;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, high, target);
        else return binarySearchRecursive(arr, low, mid - 1, target);
    }

    int linearSearch(const vector<int> &arr, int target) {
        for (int i = 0; i < (int)arr.size(); i++) {
            if (arr[i] == target) return i;
        }
        return -1;
    }
}
