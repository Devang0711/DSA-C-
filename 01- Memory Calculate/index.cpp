#include <iostream>
#include <vector>
#include <string>

using namespace std;

void primitiveMemory() {
    cout << "\n----- Primitive Data Types -----\n";
    cout << "int       : " << sizeof(int) << " Bytes\n";
    cout << "char      : " << sizeof(char) << " Bytes\n";
    cout << "float     : " << sizeof(float) << " Bytes\n";
    cout << "double    : " << sizeof(double) << " Bytes\n";
    cout << "bool      : " << sizeof(bool) << " Bytes\n";
    cout << "long long : " << sizeof(long long) << " Bytes\n";
}

void arrayMemory() {
    int n;

    cout << "\nEnter array size: ";
    cin >> n;

    cout << "Memory used by int array = "
         << n * sizeof(int)
         << " Bytes\n";
}

void matrixMemory() {
    int r, c;

    cout << "\nRows: ";
    cin >> r;

    cout << "Columns: ";
    cin >> c;

    cout << "Memory used by 2D int array = "
         << r * c * sizeof(int)
         << " Bytes\n";
}

void stringMemory() {
    string str;

    cout << "\nEnter String: ";
    cin.ignore();
    getline(cin, str);

    cout << "Characters = " << str.length() << endl;
    cout << "Approx Memory = "
         << str.length() * sizeof(char)
         << " Bytes\n";
}

void dynamicMemory() {
    int n;

    cout << "\nEnter number of integers: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Dynamic Memory Allocated = "
         << n * sizeof(int)
         << " Bytes\n";

    delete[] arr;
}

void vectorMemory() {
    int n;

    cout << "\nVector Size: ";
    cin >> n;

    vector<int> v(n);

    cout << "Approx Memory = "
         << v.capacity() * sizeof(int)
         << " Bytes\n";
}

int main() {

    int choice;

    do {

        cout << "\n====== MEMORY CALCULATOR ======\n";

        cout << "1. Primitive Data Types\n";
        cout << "2. 1D Array Memory\n";
        cout << "3. 2D Array Memory\n";
        cout << "4. String Memory\n";
        cout << "5. Dynamic Memory\n";
        cout << "6. Vector Memory\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                primitiveMemory();
                break;

            case 2:
                arrayMemory();
                break;

            case 3:
                matrixMemory();
                break;

            case 4:
                stringMemory();
                break;

            case 5:
                dynamicMemory();
                break;

            case 6:
                vectorMemory();
                break;

            case 0:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 0);

    return 0;
}