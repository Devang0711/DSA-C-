#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    int id;
    string name;
    float marks;

    void input()
    {
        cout << "Enter ID    : ";
        cin >> id;

        cin.ignore();

        cout << "Enter Name  : ";
        getline(cin, name);

        cout << "Enter Marks : ";
        cin >> marks;
    }

    void display()
    {
        cout << "\n----------------------------";
        cout << "\nID    : " << id;
        cout << "\nName  : " << name;
        cout << "\nMarks : " << marks;
        cout << "\n----------------------------\n";
    }
};

int main()
{
    Student *students = nullptr;
    int size = 0;
    int choice;

    do
    {
        cout << "\n====== Student Record System ======\n";
        cout << "1. Create Records\n";
        cout << "2. Display Records\n";
        cout << "3. Search Student\n";
        cout << "4. Update Marks\n";
        cout << "5. Delete All Records\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (students != nullptr)
            {
                delete[] students;
            }

            cout << "Enter Number of Students : ";
            cin >> size;

            students = new Student[size];

            for (int i = 0; i < size; i++)
            {
                cout << "\nStudent " << i + 1 << endl;
                students[i].input();
            }

            cout << "\nRecords Created Successfully.\n";
            break;
        }

        case 2:
        {
            if (students == nullptr)
            {
                cout << "No Records Found.\n";
                break;
            }

            for (int i = 0; i < size; i++)
            {
                students[i].display();
            }

            break;
        }

        case 3:
        {
            if (students == nullptr)
            {
                cout << "No Records Found.\n";
                break;
            }

            int searchID;
            cout << "Enter Student ID : ";
            cin >> searchID;

            bool found = false;

            for (int i = 0; i < size; i++)
            {
                if (students[i].id == searchID)
                {
                    students[i].display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student Not Found.\n";

            break;
        }

        case 4:
        {
            if (students == nullptr)
            {
                cout << "No Records Found.\n";
                break;
            }

            int id;
            float newMarks;

            cout << "Enter Student ID : ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < size; i++)
            {
                if (students[i].id == id)
                {
                    cout << "Enter New Marks : ";
                    cin >> newMarks;

                    students[i].marks = newMarks;

                    cout << "Marks Updated Successfully.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student Not Found.\n";

            break;
        }

        case 5:
        {
            delete[] students;
            students = nullptr;
            size = 0;

            cout << "All Records Deleted Successfully.\n";
            break;
        }

        case 0:
        {
            delete[] students;
            cout << "Thank You.\n";
            break;
        }

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 0);

    return 0;
}