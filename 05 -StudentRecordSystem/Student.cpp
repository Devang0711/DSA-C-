#include "Student.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

Student::Student() {
    rollNo = 0;
    name = "";
    for (int i = 0; i < NUM_SUBJECTS; i++) marks[i] = 0.0f;
    total = 0.0f;
    average = 0.0f;
    grade = 'F';
}

Student::Student(int roll, const string &n, float m[NUM_SUBJECTS]) {
    rollNo = roll;
    name = n;
    for (int i = 0; i < NUM_SUBJECTS; i++) marks[i] = m[i];
    calculateResult();
}

void Student::setRollNo(int roll) { rollNo = roll; }
void Student::setName(const string &n) { name = n; }

void Student::setMarks(float m[NUM_SUBJECTS]) {
    for (int i = 0; i < NUM_SUBJECTS; i++) marks[i] = m[i];
    calculateResult();
}

int Student::getRollNo() const { return rollNo; }
string Student::getName() const { return name; }

float Student::getMarks(int index) const {
    if (index < 0 || index >= NUM_SUBJECTS) return 0.0f;
    return marks[index];
}

float Student::getTotal() const { return total; }
float Student::getAverage() const { return average; }
char Student::getGrade() const { return grade; }

void Student::calculateResult() {
    total = 0.0f;
    for (int i = 0; i < NUM_SUBJECTS; i++) total += marks[i];
    average = total / NUM_SUBJECTS;

    if (average >= 90) grade = 'A';
    else if (average >= 75) grade = 'B';
    else if (average >= 60) grade = 'C';
    else if (average >= 40) grade = 'D';
    else grade = 'F';
}

void Student::display() const {
    cout << left << setw(8) << rollNo
         << setw(20) << name
         << setw(10) << fixed << setprecision(2) << total
         << setw(10) << fixed << setprecision(2) << average
         << setw(6) << grade << "\n";
}

// Format: rollNo|name|m1,m2,m3,m4,m5
string Student::toFileString() const {
    ostringstream oss;
    oss << rollNo << "|" << name << "|";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        oss << marks[i];
        if (i != NUM_SUBJECTS - 1) oss << ",";
    }
    return oss.str();
}

Student Student::fromFileString(const string &line) {
    Student s;
    size_t p1 = line.find('|');
    size_t p2 = line.find('|', p1 + 1);
    if (p1 == string::npos || p2 == string::npos) return s;

    int roll = stoi(line.substr(0, p1));
    string name = line.substr(p1 + 1, p2 - p1 - 1);
    string marksStr = line.substr(p2 + 1);

    float m[NUM_SUBJECTS] = {0};
    stringstream ss(marksStr);
    string token;
    int idx = 0;
    while (getline(ss, token, ',') && idx < NUM_SUBJECTS) {
        m[idx++] = stof(token);
    }

    s.setRollNo(roll);
    s.setName(name);
    s.setMarks(m);
    return s;
}
