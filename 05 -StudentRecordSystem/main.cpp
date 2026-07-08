#include <iostream>
#include <vector>
#include "Student.h"
#include "LinkedList.h"
#include "Searching.h"
#include "Sorting.h"
#include "Statistics.h"
#include "Utility.h"

using namespace std;

const string DATA_FILE = "students.dat";

void addStudent(LinkedList &list) {
    Utility::printHeader("Add New Student");

    int roll = Utility::getValidInt("Enter Roll No: ");
    if (list.findByRoll(roll) != nullptr) {
        cout << "A student with this roll number already exists!\n";
        return;
    }

    string name = Utility::getValidName("Enter Name: ");

    float marks[NUM_SUBJECTS];
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        marks[i] = Utility::getValidFloat("Enter Marks for Subject " + to_string(i + 1) + " (0-100): ");
    }

    Student s(roll, name, marks);
    list.insertAtEnd(s);
    cout << "Student added successfully!\n";
}

void displayStudents(const LinkedList &list) {
    Utility::printHeader("All Student Records");
    list.displayAll();
}

void searchStudent(const LinkedList &list) {
    Utility::printHeader("Search Student");
    cout << "1. Search by Roll No (Linear Search)\n";
    cout << "2. Search by Name\n";
    int choice = Utility::getValidInt("Enter choice: ");

    if (choice == 1) {
        int roll = Utility::getValidInt("Enter Roll No to search: ");
        Node* result = Searching::linearSearchByRoll(list, roll);
        if (result != nullptr) {
            cout << "\nStudent found:\n";
            result->data.display();
        } else {
            cout << "Student not found.\n";
        }
    } else if (choice == 2) {
        cin.ignore();
        string name = Utility::getValidName("Enter Name to search: ");
        Node* result = Searching::linearSearchByName(list, name);
        if (result != nullptr) {
            cout << "\nStudent found:\n";
            result->data.display();
        } else {
            cout << "Student not found.\n";
        }
    } else {
        cout << "Invalid choice.\n";
    }
}

void sortStudents(LinkedList &list) {
    Utility::printHeader("Sort Students");
    cout << "1. Sort by Roll No (ascending)\n";
    cout << "2. Sort by Name (ascending)\n";
    cout << "3. Sort by Average Marks (descending)\n";
    int choice = Utility::getValidInt("Enter choice: ");

    switch (choice) {
        case 1: Sorting::bubbleSortByRoll(list, true); break;
        case 2: Sorting::bubbleSortByName(list, true); break;
        case 3: Sorting::selectionSortByAverage(list, true); break;
        default: cout << "Invalid choice.\n"; return;
    }
    cout << "Sorted successfully!\n";
    list.displayAll();
}

void deleteStudent(LinkedList &list) {
    Utility::printHeader("Delete Student");
    int roll = Utility::getValidInt("Enter Roll No to delete: ");
    if (list.deleteByRoll(roll)) {
        cout << "Student deleted successfully!\n";
    } else {
        cout << "Student with roll number " << roll << " not found.\n";
    }
}

void showStatistics(const LinkedList &list) {
    Statistics::showStatistics(list);
}

void saveData(const LinkedList &list) {
    if (Utility::saveToFile(list, DATA_FILE)) {
        cout << "Data saved to '" << DATA_FILE << "' successfully!\n";
    } else {
        cout << "Failed to save data.\n";
    }
}

void loadData(LinkedList &list) {
    if (Utility::loadFromFile(list, DATA_FILE)) {
        cout << "Data loaded from '" << DATA_FILE << "' successfully! ("
             << list.getSize() << " records)\n";
    } else {
        cout << "Failed to load data. File may not exist yet.\n";
    }
}

void showMenu() {
    Utility::printHeader("STUDENT RECORD MANAGEMENT SYSTEM");
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Sort Students\n";
    cout << "5. Delete Student\n";
    cout << "6. Show Statistics\n";
    cout << "7. Save Data to File\n";
    cout << "8. Load Data from File\n";
    cout << "9. Exit\n";
    Utility::printLine();
}

int main() {
    LinkedList studentList;
    bool running = true;

    cout << "Welcome to the Student Record Management System\n";

    while (running) {
        showMenu();
        int choice = Utility::getValidInt("Enter your choice: ");

        switch (choice) {
            case 1: addStudent(studentList); break;
            case 2: displayStudents(studentList); break;
            case 3: searchStudent(studentList); break;
            case 4: sortStudents(studentList); break;
            case 5: deleteStudent(studentList); break;
            case 6: showStatistics(studentList); break;
            case 7: saveData(studentList); break;
            case 8: loadData(studentList); break;
            case 9:
                cout << "Thank you for using the system. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << "\n";
    }

    return 0;
}
