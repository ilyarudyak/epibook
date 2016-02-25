#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList list;
    list.makeListWithCycle();
    list.printListWithCycle();
    cout << list.detectCycleSet() << endl;
    cout << list.detectCycleFloyd() << endl;
    return 0;
}