#ifndef UTILITY_H
#define UTILITY_H

#include <string>
using namespace std;

namespace Utility {
    int getValidInt(const string &prompt);
    void displayIntArray(const int arr[], int n);
    void printHeader(const string &title);
    void printLine(char ch = '-', int len = 60);
    void pause();
}

#endif // UTILITY_H
