//
// Created by Ilya Rudyak on 5/18/16.
//

#ifndef INC_10_HEAP_STACKWITHHEAP_H
#define INC_10_HEAP_STACKWITHHEAP_H

#include <utility>
#include <queue>
using namespace std;

template <typename T> class CompareStandard {
public:
    const bool operator()(  const pair<int, T>&lhs,
                            const pair<int, T>&rhs) const {
        return lhs.first < rhs.first;
    }
};

template <typename T> class StackWithHeap {

public:
    StackWithHeap() {
        order = 0;
    };

    const T& pop() {
        T tmp = pq.top().second;
        pq.pop();
        return tmp;
    }
    void push (const T& t) {
        pq.push(make_pair(order, t));
        order++;
    }
    bool isEmpty() {
        return pq.empty();
    }
    void show() {
        while (!isEmpty()) {
            cout << pop() << " ";
        }
        cout << endl;
    }


private:
    int order;
    priority_queue<pair<int, T>, vector<pair<int, T>>, CompareStandard<T>> pq;

};

#endif //INC_10_HEAP_STACKWITHHEAP_H























