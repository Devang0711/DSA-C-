#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"

struct Node {
    Student data;
    Node* next;
    Node(const Student &s) : data(s), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void insertAtEnd(const Student &s);
    bool deleteByRoll(int roll);
    void clear();

    Node* getHead() const;
    int getSize() const;
    bool isEmpty() const;

    void displayAll() const;
    Node* findByRoll(int roll) const;
    Node* findByName(const string &name) const;

    void swapData(Node* a, Node* b); // used by sorting algorithms
};

#endif // LINKEDLIST_H
