//
// Created by Ilya Rudyak on 2/26/16.
//

#ifndef INC_7_9_REVERSE_LINKEDLIST_H
#define INC_7_9_REVERSE_LINKEDLIST_H

class Node {
public:
    Node() : next(nullptr) { }
    Node(int data, Node *next = nullptr) {
        this->data = data;
        this->next = next;
    }
    int data;
    Node *next;
};

class LinkedList {

public:
    LinkedList() : head(nullptr), tail(nullptr), rev(nullptr) { }

    int isEmpty() {
        return head == nullptr;
    }
    void addToHead(int);
    void printList() const;

    // reverse list
    void reverseNonRec();
    void swap();


private:
    Node *head;
    Node *tail;
    Node *rev;
};


#endif //INC_7_9_REVERSE_LINKEDLIST_H




















