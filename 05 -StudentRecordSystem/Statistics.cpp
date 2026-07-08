#include "Statistics.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace Statistics {

    float classAverage(const LinkedList &list) {
        if (list.isEmpty()) return 0.0f;
        float sum = 0.0f;
        int n = 0;
        Node* temp = list.getHead();
        while (temp != nullptr) {
            sum += temp->data.getAverage();
            n++;
            temp = temp->next;
        }
        return sum / n;
    }

    Student topStudent(const LinkedList &list, bool &found) {
        found = false;
        Student best;
        if (list.isEmpty()) return best;

        Node* temp = list.getHead();
        best = temp->data;
        found = true;
        temp = temp->next;
        while (temp != nullptr) {
            if (temp->data.getAverage() > best.getAverage()) best = temp->data;
            temp = temp->next;
        }
        return best;
    }

    Student lowestStudent(const LinkedList &list, bool &found) {
        found = false;
        Student worst;
        if (list.isEmpty()) return worst;

        Node* temp = list.getHead();
        worst = temp->data;
        found = true;
        temp = temp->next;
        while (temp != nullptr) {
            if (temp->data.getAverage() < worst.getAverage()) worst = temp->data;
            temp = temp->next;
        }
        return worst;
    }

    void subjectWiseAverage(const LinkedList &list) {
        if (list.isEmpty()) {
            cout << "No records available.\n";
            return;
        }

        float sums[NUM_SUBJECTS] = {0};
        int n = 0;
        Node* temp = list.getHead();
        while (temp != nullptr) {
            for (int i = 0; i < NUM_SUBJECTS; i++) sums[i] += temp->data.getMarks(i);
            n++;
            temp = temp->next;
        }

        cout << "\nSubject-wise Average:\n";
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            cout << "  Subject " << (i + 1) << ": "
                 << fixed << setprecision(2) << (sums[i] / n) << "\n";
        }
    }

    int countAboveAverage(const LinkedList &list) {
        if (list.isEmpty()) return 0;
        float avg = classAverage(list);
        int count = 0;
        Node* temp = list.getHead();
        while (temp != nullptr) {
            if (temp->data.getAverage() > avg) count++;
            temp = temp->next;
        }
        return count;
    }

    int countPassed(const LinkedList &list) {
        int count = 0;
        Node* temp = list.getHead();
        while (temp != nullptr) {
            if (temp->data.getGrade() != 'F') count++;
            temp = temp->next;
        }
        return count;
    }

    void showStatistics(const LinkedList &list) {
        if (list.isEmpty()) {
            cout << "No records available to compute statistics.\n";
            return;
        }

        int total = list.getSize();
        float avg = classAverage(list);
        int aboveAvg = countAboveAverage(list);
        int passed = countPassed(list);

        bool found;
        Student top = topStudent(list, found);
        Student low = lowestStudent(list, found);

        cout << "\n===== Class Statistics =====\n";
        cout << "Total Students   : " << total << "\n";
        cout << "Class Average    : " << fixed << setprecision(2) << avg << "\n";
        cout << "Students Passed  : " << passed << " / " << total << "\n";
        cout << "Above Average    : " << aboveAvg << "\n";
        cout << "Top Student      : " << top.getName() << " (Roll " << top.getRollNo()
             << ", Avg " << fixed << setprecision(2) << top.getAverage() << ")\n";
        cout << "Lowest Student   : " << low.getName() << " (Roll " << low.getRollNo()
             << ", Avg " << fixed << setprecision(2) << low.getAverage() << ")\n";

        subjectWiseAverage(list);
    }
}
