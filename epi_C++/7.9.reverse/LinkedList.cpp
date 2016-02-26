#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::addToHead(int data) {
    head = new Node(data, head);
    if (tail == nullptr) {
        rev = tail = head;
    }
}

// ------------- utility functions -------------

void LinkedList::printList() const {

    Node *walker = head;
    int count = 0;
    while (walker != nullptr && count < 5) {
        if (walker->next != nullptr && count != 4) {
            cout << walker->data << "->";
        } else {
            cout << walker->data;
        }
        walker = walker->next;
        count ++;
    }

    cout << " head=" << head->data << " tail=" << tail->data << endl;

}

void LinkedList::reverseNonRec() {

    Node *prev = head; Node *walker = head;
    while (walker != rev) {
        prev = walker;
        walker = walker->next;

    }
    rev = walker->next = prev;
}

void LinkedList::swap() {
    Node *tmp = head;
    head = tail;
    tail = tmp;
}














