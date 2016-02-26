//
// Created by Ilya Rudyak on 2/26/16.
//

#ifndef INC_7_3_CIRCULAR_MEDIAN_CIRCULARLIST_H
#define INC_7_3_CIRCULAR_MEDIAN_CIRCULARLIST_H


class Node {
public:
    Node() : data(0), next(nullptr) { }
    Node(int data, Node *next = nullptr) {
        this->data = data;
        this->next = next;
    }
    int data;
    Node *next;
};

class CircularList {

public:
    CircularList() : cursor(nullptr) { };

    bool empty();
    int head();                         // node after cursor
    int tail();                         // node at cursor
    void advance();                     // advance cursor one position forward
    void addAfterCursor(int data);      // add after cursor
    void removeAfterCursor();           // remove after cursor
    void printList();                   // print list

    // we consider simplest case
    // when we have odd number of nodes
    int findMedian();

private:
    Node *cursor;
};


#endif //INC_7_3_CIRCULAR_MEDIAN_CIRCULARLIST_H
