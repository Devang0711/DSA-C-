#ifndef UTILITY_H
#define UTILITY_H

#include "LinkedList.h"
#include <string>

namespace Utility {
    int getValidInt(const string &prompt);
    float getValidFloat(const string &prompt, float minVal = 0.0f, float maxVal = 100.0f);
    string getValidName(const string &prompt);

    void printHeader(const string &title);
    void printLine(char ch = '-', int len = 60);
    void pause();

    bool saveToFile(const LinkedList &list, const string &filename);
    bool loadFromFile(LinkedList &list, const string &filename);
}

#endif // UTILITY_H
