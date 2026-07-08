#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    int marks;

    void input()
    {
        cout << "\nEnter Student Name : ";
        cin >> name;

        cout << "Enter Marks : ";
        cin >> marks;
    }

    void display()
    {
        cout << "\n-------------------------";
        cout << "\nName  : " << name;
        cout << "\nMarks : " << marks;

        if (marks >= 90)
            cout << "\nCategory : Excellent";
        else if (marks >= 75)
            cout << "\nCategory : Very Good";
        else if (marks >= 60)
            cout << "\nCategory : Good";
        else if (marks >= 40)
            cout << "\nCategory : Average";
        else
            cout << "\nCategory : Fail";

        cout << "\n-------------------------\n";
    }
};

int main()
{
    int n;

    cout << "Enter Number of Students : ";
    cin >> n;

    Student students[n];

    for (int i = 0; i < n; i++)
    {
        students[i].input();
    }

    cout << "\n======= Student Categories =======";

    for (int i = 0; i < n; i++)
    {
        students[i].display();
    }

    return 0;
}