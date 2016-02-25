#ifndef INC_7_LINKED_LIST_LINKEDLIST_H
#define INC_7_LINKED_LIST_LINKEDLIST_H

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

    const int kNumberOfNodes = 5;

    LinkedList() : head(nullptr) { }

    int isEmpty() {
        return head == nullptr;
    }
    void addToHead(int);
    void printList() const;

    // detect cycle
    void makeListWithCycle();
    void printListWithCycle();
    bool detectCycleSet();
    bool detectCycleFloyd();



private:
    Node *head;

};


#endif //INC_7_LINKED_LIST_LINKEDLIST_H














