#ifndef STATISTICS_H
#define STATISTICS_H

#include "LinkedList.h"

namespace Statistics {
    void showStatistics(const LinkedList &list);
    float classAverage(const LinkedList &list);
    Student topStudent(const LinkedList &list, bool &found);
    Student lowestStudent(const LinkedList &list, bool &found);
    void subjectWiseAverage(const LinkedList &list);
    int countAboveAverage(const LinkedList &list);
    int countPassed(const LinkedList &list); // grade != 'F'
}

#endif // STATISTICS_H
