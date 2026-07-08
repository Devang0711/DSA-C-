#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <string>
using namespace std;

namespace Utility {
    int getValidInt(const string &prompt);
    vector<int> getIntArray(const string &prompt);
    void displayArray(const vector<int> &arr);
    void printHeader(const string &title);
    void printLine(char ch = '-', int len = 60);
    void pause();
}

#endif // UTILITY_H
