#include "Utility.h"
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

namespace Utility {

    int getValidInt(const string &prompt) {
        int value;
        while (true) {
            cout << prompt;
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid integer.\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }

    float getValidFloat(const string &prompt, float minVal, float maxVal) {
        float value;
        while (true) {
            cout << prompt;
            cin >> value;
            if (cin.fail() || value < minVal || value > maxVal) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between "
                     << minVal << " and " << maxVal << ".\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }

    string getValidName(const string &prompt) {
        string name;
        while (true) {
            cout << prompt;
            getline(cin, name);
            if (name.empty()) {
                cout << "Name cannot be empty. Please try again.\n";
            } else {
                return name;
            }
        }
    }

    void printHeader(const string &title) {
        printLine('=', 60);
        cout << title << "\n";
        printLine('=', 60);
    }

    void printLine(char ch, int len) {
        cout << string(len, ch) << "\n";
    }

    void pause() {
        cout << "\nPress Enter to continue...";
        cin.get();
    }

    bool saveToFile(const LinkedList &list, const string &filename) {
        ofstream out(filename);
        if (!out.is_open()) return false;

        Node* temp = list.getHead();
        while (temp != nullptr) {
            out << temp->data.toFileString() << "\n";
            temp = temp->next;
        }
        out.close();
        return true;
    }

    bool loadFromFile(LinkedList &list, const string &filename) {
        ifstream in(filename);
        if (!in.is_open()) return false;

        list.clear();
        string line;
        while (getline(in, line)) {
            if (line.empty()) continue;
            Student s = Student::fromFileString(line);
            list.insertAtEnd(s);
        }
        in.close();
        return true;
    }
}
