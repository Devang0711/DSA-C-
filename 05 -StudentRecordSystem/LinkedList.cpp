#include "LinkedList.h"
#include <iostream>
#include <iomanip>

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}

void LinkedList::insertAtEnd(const Student &s) {
    Node* newNode = new Node(s);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
    size++;
}

bool LinkedList::deleteByRoll(int roll) {
    if (head == nullptr) return false;

    if (head->data.getRollNo() == roll) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        size--;
        return true;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr) {
        if (curr->data.getRollNo() == roll) {
            prev->next = curr->next;
            delete curr;
            size--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

Node* LinkedList::getHead() const { return head; }
int LinkedList::getSize() const { return size; }
bool LinkedList::isEmpty() const { return head == nullptr; }

void LinkedList::displayAll() const {
    if (isEmpty()) {
        cout << "No records found.\n";
        return;
    }
    cout << left << setw(8) << "Roll" << setw(20) << "Name"
         << setw(10) << "Total" << setw(10) << "Average"
         << setw(6) << "Grade" << "\n";
    cout << string(54, '-') << "\n";

    Node* temp = head;
    while (temp != nullptr) {
        temp->data.display();
        temp = temp->next;
    }
}

Node* LinkedList::findByRoll(int roll) const {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.getRollNo() == roll) return temp;
        temp = temp->next;
    }
    return nullptr;
}

Node* LinkedList::findByName(const string &name) const {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.getName() == name) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::swapData(Node* a, Node* b) {
    if (a == nullptr || b == nullptr || a == b) return;
    Student temp = a->data;
    a->data = b->data;
    b->data = temp;
}
