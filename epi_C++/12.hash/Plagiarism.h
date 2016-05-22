//
// Created by Ilya Rudyak on 5/22/16.
//

#ifndef INC_12_HASH_PLAGIARISM_H
#define INC_12_HASH_PLAGIARISM_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Plagiarism {

public:
    Plagiarism(fstream &in, int k) {
        this->k = k;
        string word;
        while (in >> word) {
            addToMap(word);
        }

    }

    bool checkPlagiarism() {
        for (auto textPair : textMap) {
            set<string> words = textPair.second;

            if (words.size() > 1) {
                cout << textPair.first << ": ";
                for (auto word : words) {
                    cout << word << " ";
                }
                cout << endl;
            }
        }
    }


private:
    int k;
    map<string, set<string>> textMap;
    void addToMap(const string &word) {
//        cout << "word: " << word << " ";
        for (int i = 0; i < word.size() - k + 1; ++i) {
            string ksubstr = word.substr((unsigned long) i, (unsigned long) k);
//            cout << ksubstr << " ";
            textMap[ksubstr].insert(word);
        }
//        cout << endl;
    }

};

#endif //INC_12_HASH_PLAGIARISM_H






















