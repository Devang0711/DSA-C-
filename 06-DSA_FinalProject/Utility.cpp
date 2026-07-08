#include "Utility.h"
#include <iostream>
#include <sstream>
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
                // No more input available (e.g. input stream/file ended).
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

    vector<int> getIntArray(const string &prompt) {
        cout << prompt;
        string line;
        getline(cin, line);

        vector<int> arr;
        stringstream ss(line);
        int val;
        while (ss >> val) arr.push_back(val);
        return arr;
    }

    void displayArray(const vector<int> &arr) {
        cout << "[ ";
        for (int v : arr) cout << v << " ";
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
