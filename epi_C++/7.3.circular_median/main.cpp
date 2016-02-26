#include <iostream>
#include "CircularList.h"

using namespace std;

int main() {

    CircularList list;
    list.addAfterCursor(0);
    for (int i = 4; i > 0; --i) {
        list.addAfterCursor(i);
    }
    list.printList();

    cout << list.findMedian() << endl;
    return 0;
}