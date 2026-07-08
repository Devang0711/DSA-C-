#include <iostream>
#include <string>

using namespace std;

class Escalator
{
private:
    string *people;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Escalator(int size)
    {
        capacity = size;
        people = new string[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Escalator()
    {
        delete[] people;
    }

    void enterPerson()
    {
        if (count == capacity)
        {
            cout << "\nEscalator is Full!\n";
            return;
        }

        string name;
        cout << "Enter Person Name: ";
        cin >> name;

        rear = (rear + 1) % capacity;
        people[rear] = name;
        count++;

        cout << name << " entered the escalator.\n";
    }

    void exitPerson()
    {
        if (count == 0)
        {
            cout << "\nEscalator is Empty!\n";
            return;
        }

        cout << people[front] << " exited the escalator.\n";

        front = (front + 1) % capacity;
        count--;
    }

    void display()
    {
        if (count == 0)
        {
            cout << "\nNo people on escalator.\n";
            return;
        }

        cout << "\nPeople on Escalator:\n";

        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % capacity;
            cout << i + 1 << ". " << people[index] << endl;
        }
    }
};

int main()
{
    int size;

    cout << "Enter Escalator Capacity: ";
    cin >> size;

    Escalator escalator(size);

    int choice;

    do
    {
        cout << "\n====== ESCALATOR SYSTEM ======\n";
        cout << "1. Enter Person\n";
        cout << "2. Exit Person\n";
        cout << "3. Display People\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            escalator.enterPerson();
            break;

        case 2:
            escalator.exitPerson();
            break;

        case 3:
            escalator.display();
            break;

        case 0:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 0);

    return 0;
}