#include <iostream>
#include "7.1.merge/LinkedList.h"

using namespace std;



int main() {

    LinkedList l, m;
    l.addToHead(7);
    l.addToHead(5);
    l.addToHead(2);
    m.addToHead(11);
    m.addToHead(3);

    l.printList();
    m.printList();

    l.merge(m);
    l.printList();

    return 0;
}