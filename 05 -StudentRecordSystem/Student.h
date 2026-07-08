#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

const int NUM_SUBJECTS = 5;

class Student {
private:
    int rollNo;
    string name;
    float marks[NUM_SUBJECTS];
    float total;
    float average;
    char grade;

public:
    Student();
    Student(int roll, const string &n, float m[NUM_SUBJECTS]);

    // Setters
    void setRollNo(int roll);
    void setName(const string &n);
    void setMarks(float m[NUM_SUBJECTS]);

    // Getters
    int getRollNo() const;
    string getName() const;
    float getMarks(int index) const;
    float getTotal() const;
    float getAverage() const;
    char getGrade() const;

    // Behaviour
    void calculateResult();
    void display() const;

    // Persistence helpers (used by Utility save/load)
    string toFileString() const;
    static Student fromFileString(const string &line);
};

#endif // STUDENT_H
