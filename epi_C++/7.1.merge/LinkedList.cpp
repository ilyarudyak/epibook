#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::addToHead(int data) {
    head = new Node(data, head);
}


void LinkedList::merge(LinkedList &other) {

    if (isEmpty()) {
        head = other.head;
        return;
    }

    Node *walker = head; Node *prev = head;
    Node *walker2 = other.head;
    while (walker != nullptr && walker2 != nullptr) {
        if (walker->data <= walker2->data) {
            cout << "data=" << walker->data <<
            "data2="<< walker2->data<< endl;
            prev = walker;
            walker = walker->next;
        } else {
            cout << "data=" << walker->data <<
            "data2="<< walker2->data<< endl;
            prev->next = walker2;
            walker2 = walker2->next;
            prev->next->next = walker;
            prev = prev->next;
        }
    }

    if (walker == nullptr) {
        prev->next = walker2;
    }

}

// ------------- utility functions -------------

void LinkedList::printList() const {

    Node *walker = head;
    while (walker != nullptr) {
        if (walker->next != nullptr) {
            cout << walker->data << "->";
        } else {
            cout << walker->data << endl;
        }
        walker = walker->next;
    }

}


