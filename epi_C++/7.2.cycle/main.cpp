#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    // test cycle finder
    LinkedList list;
//    list.makeListWithCycle();
//    list.printListWithCycle();
//    cout << list.detectCycleSet() << endl;
//    cout << list.detectCycleFloyd() << endl;

    // test median
    for (int i = 0; i < 5; ++i) {
        list.addToHead(i);
    }
    cout << "median=" << list.findMedian() << endl;




    return 0;
}