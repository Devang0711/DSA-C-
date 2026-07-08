#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void insertAtFront(int val);
    void insertAtEnd(int val);
    bool deleteValue(int val);
    bool search(int val) const;
    void display() const;
    void reverse();
    int getSize() const;
    void clear();
};

#endif // LINKEDLIST_H
