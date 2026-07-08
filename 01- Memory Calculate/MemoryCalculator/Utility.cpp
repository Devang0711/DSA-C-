#include "Utility.h"
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

namespace Utility {

    int getValidInt(const string &prompt) {
        int value;
        while (true) {
            cout << prompt;
            cin >> value;
            if (cin.eof()) {
                cout << "\nNo more input available. Exiting.\n";
                exit(0);
            }
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

    void displayIntArray(const int arr[], int n) {
        cout << "[ ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "]\n";
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
}
