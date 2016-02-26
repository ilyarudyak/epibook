#include <iostream>
#include <set>
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

void LinkedList::makeListWithCycle() {
    Node *last = nullptr;
    Node *first = nullptr;
    for (int i = kNumberOfNodes - 1; i >= 0; --i) {
        Node *tmp = new Node(i, head);

        // save nodes to make a cycle
        if (i == kNumberOfNodes - 1) { last = tmp; }
        if (i == 1) { first = tmp; }

        head = tmp;
    }

    // make cycle
    last->next = first;

}

void LinkedList::printListWithCycle() {
    Node *walker = head;
    int counter = 0;
    while (walker != nullptr && counter <= kNumberOfNodes) {
        if (walker->next != nullptr && counter < kNumberOfNodes) {
            cout << walker->data << "->";
        } else {
            cout << walker->data << endl;
        }
        walker = walker->next;
        counter++;
    }
}

bool LinkedList::detectCycleSet() {
    set<Node *> nodes;
    Node *walker = head;
    while (walker != nullptr) {
        if (!nodes.insert(walker).second) {
            return true;
        }
        walker = walker->next;
    }

    return false;
}

bool LinkedList::detectCycleFloyd() {
    Node *fast = head;
    Node *slow = head;
    while (true) {
        if (fast == slow) { return true; }

        if (slow == nullptr) { break; }
        else { slow = slow->next; }

        if (fast == nullptr || fast->next == nullptr) { break ; }
        else { fast = fast->next->next; }
    }
    return false;
}

int LinkedList::findMedian() {
    Node *slow = head;
    Node *fast = head;

    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}
