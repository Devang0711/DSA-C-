#include "Sorting.h"

namespace Sorting {

    void bubbleSortByRoll(LinkedList &list, bool ascending) {
        if (list.isEmpty()) return;

        bool swapped;
        do {
            swapped = false;
            Node* curr = list.getHead();
            while (curr != nullptr && curr->next != nullptr) {
                bool condition = ascending
                    ? (curr->data.getRollNo() > curr->next->data.getRollNo())
                    : (curr->data.getRollNo() < curr->next->data.getRollNo());

                if (condition) {
                    list.swapData(curr, curr->next);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
    }

    void bubbleSortByName(LinkedList &list, bool ascending) {
        if (list.isEmpty()) return;

        bool swapped;
        do {
            swapped = false;
            Node* curr = list.getHead();
            while (curr != nullptr && curr->next != nullptr) {
                bool condition = ascending
                    ? (curr->data.getName() > curr->next->data.getName())
                    : (curr->data.getName() < curr->next->data.getName());

                if (condition) {
                    list.swapData(curr, curr->next);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
    }

    void selectionSortByAverage(LinkedList &list, bool descending) {
        if (list.isEmpty()) return;

        Node* i = list.getHead();
        while (i != nullptr) {
            Node* selected = i;
            Node* j = i->next;
            while (j != nullptr) {
                bool condition = descending
                    ? (j->data.getAverage() > selected->data.getAverage())
                    : (j->data.getAverage() < selected->data.getAverage());

                if (condition) selected = j;
                j = j->next;
            }
            if (selected != i) list.swapData(i, selected);
            i = i->next;
        }
    }
}
