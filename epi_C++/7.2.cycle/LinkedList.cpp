#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::addToHead(int data) {
    head = new Node(data, head);
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


