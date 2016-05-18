//
// Created by Ilya Rudyak on 5/18/16.
//

#ifndef INC_10_HEAP_FILEMERGER_H
#define INC_10_HEAP_FILEMERGER_H

#include <vector>
#include <queue>
#include <utility>
using namespace std;

class CompareInverse {
public:
    const bool operator()(  const pair<int, int>&lhs,
                            const pair<int, int>&rhs) const {
        return lhs.first > rhs.first;
    }
};

// 10.1 merging sorted files
// we put first elements (from each file) into a heap, extract min M
// and then put next element - we use file from which we extracted M
class FileMerger {

public:
    FileMerger(vector<vector<pair<int,int>>> &vectors) {
        this->vectors = vectors;
        for (int i = 0; i < vectors.size(); ++i) {
            indicies.push_back(0);
        }
    }
    void mergeVectors() {
        initialFill();
        int vectorIndex, elIndex;
        pair<int, int> minPair;
        while (!minHeap.empty()) {
            minPair = minHeap.top();
            minHeap.pop();

            cout << minPair.first << " ";

            vectorIndex = minPair.second;
            indicies[vectorIndex]++;
            elIndex = indicies[vectorIndex];
            if (elIndex < vectors[vectorIndex].size()) {
                minHeap.push(vectors[vectorIndex][elIndex]);
            }

        }
        cout << endl;
    }

private:
    vector<vector<pair<int,int>>> vectors;
    vector<int> indicies;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareInverse> minHeap;
    void initialFill() {
        for (int i = 0; i < vectors.size(); ++i) {
            minHeap.push(vectors[i][0]);
        }
    }
};

#endif //INC_10_HEAP_FILEMERGER_H






















