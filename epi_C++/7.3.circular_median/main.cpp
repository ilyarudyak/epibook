#include <iostream>
#include "CircularList.h"

using namespace std;

int main() {

    CircularList list;
    for (int i = 0; i < 5; ++i) {
        list.addAfterCursor(i);
    }
    list.printList();
    
    return 0;
}