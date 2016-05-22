//
// Created by Ilya Rudyak on 5/22/16.
//

#ifndef INC_12_HASH_NEARESTREPETITION_H
#define INC_12_HASH_NEARESTREPETITION_H

#include "vector"
#include <map>
using namespace std;

class NearestRepetition {

public:
    NearestRepetition(const vector<string> &words) :
            words(words), minDistance((int) words.size()) { }
    void closestWord() {
        string word; int index;
        for (int i = 0; i < words.size(); ++i) {
            word = words[i];
            if (wordsMap.count(word) > 0) {
                index = wordsMap[word];
                if ((i - index) < minDistance) {
                    minDistance = i - index;
                    minWord = word;
                }
            }

            // add new word or override existed one
            wordsMap[word] = i;
        }

        cout << "closest word: '" << minWord
        << "' distance=" << minDistance << endl;
    }

private:
    vector<string> words;

    map<string, int> wordsMap;
    string minWord;
    int minDistance;


};

#endif //INC_12_HASH_NEARESTREPETITION_H
