//
// Created by Ilya Rudyak on 5/18/16.
//

#ifndef INC_10_HEAP_CLOSESTSTARS_H
#define INC_10_HEAP_CLOSESTSTARS_H

#include <utility>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class CompareStars {
public:
    const bool operator()(  const pair<int, int>&lhs,
                            const pair<int, int>&rhs) const {
        return lhs.second < rhs.second;
    }
};

// 10.4 find k closest stars
// we use min heap with at most k entries
class ClosestStars {

public:
    ClosestStars(vector<pair<int, int>> stars, int k) {
        this->stars = stars;
        this->k = k;
    }

    void findClosest() {
        for (int i = 0; i < stars.size(); ++i) {
            maxHeap.push(stars[i]);
            if (maxHeap.size() > k) {
                cout << maxHeap.top().second << " ";
                maxHeap.pop();
            }
        }

        cout << endl;
        cout << "size=" << maxHeap.size() << endl;
        for (int j = 0; j < 5; ++j) {
            cout << maxHeap.top().first << " ";
            maxHeap.pop();
        }
        cout << endl;
    }

private:
    int k;
    vector<pair<int, int>> stars;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareStars> maxHeap;

};

#endif //INC_10_HEAP_CLOSESTSTARS_H
