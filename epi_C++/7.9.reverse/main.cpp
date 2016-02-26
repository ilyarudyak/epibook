#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList list;
    for (int i = 4; i >=0 ; --i) {
        list.addToHead(i);
    }
    list.printList();

    for (int j = 0; j < 5; ++j) {
        list.reverseNonRec();
    }
    list.swap();
    list.printList();

    return 0;
}