#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::clear() {
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    size = 0;
}

void LinkedList::insertAtFront(int val) {
    ListNode* node = new ListNode(val);
    node->next = head;
    head = node;
    size++;
}

void LinkedList::insertAtEnd(int val) {
    ListNode* node = new ListNode(val);
    if (head == nullptr) {
        head = node;
    } else {
        ListNode* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = node;
    }
    size++;
}

bool LinkedList::deleteValue(int val) {
    if (head == nullptr) return false;

    if (head->data == val) {
        ListNode* toDelete = head;
        head = head->next;
        delete toDelete;
        size--;
        return true;
    }

    ListNode* prev = head;
    ListNode* curr = head->next;
    while (curr != nullptr) {
        if (curr->data == val) {
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

bool LinkedList::search(int val) const {
    ListNode* curr = head;
    while (curr != nullptr) {
        if (curr->data == val) return true;
        curr = curr->next;
    }
    return false;
}

void LinkedList::display() const {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    ListNode* curr = head;
    cout << "HEAD -> ";
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << " -> NULL\n";
}

void LinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int LinkedList::getSize() const { return size; }
