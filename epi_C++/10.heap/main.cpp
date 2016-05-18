#include <iostream>
#include <vector>
#include <utility>
#include "BinaryHeap.h"
#include "FileMerger.h"
#include "StackWithHeap.h"
using namespace std;


int main() {

    // 10.3 implement stack with heap
    StackWithHeap<int> stack;
    stack.push(3); stack.push(5); stack.push(2);
    stack.push(4); stack.push(1);
    stack.show();


    // 10.1 merging sorted files
//    vector<vector<pair<int, int>>> vectors = {
//            {make_pair(57, 0), make_pair(131, 0), make_pair(493, 0)},
//            {make_pair(221, 1), make_pair(294, 1)},
//            {make_pair(339, 2), make_pair(418, 2), make_pair(452, 2)},
//            {make_pair(190, 3), make_pair(442, 3)}
//    };
//    FileMerger fm(vectors);
//    fm.mergeVectors();


    // check heap implementation
//    BinaryHeap<int> heap;
//    heap.insert(1); heap.insert(2); heap.insert(3);
//    cout << "min=" << heap.findMin() << endl;
//
//    heap.insert(4); heap.insert(5); heap.insert(0);
//    cout << "min=" << heap.findMin() << endl;
//
//    heap.deleteMin();
//    cout << "min=" << heap.findMin() << endl;

    return 0;
}