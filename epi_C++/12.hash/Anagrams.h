//
// Created by Ilya Rudyak on 5/22/16.
//

#ifndef INC_12_HASH_ANAGRAMS_H
#define INC_12_HASH_ANAGRAMS_H

#include <map>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


class Anagram {

public:

    Anagram(fstream &in) {
        string word, sortedWord;
        int maxLen = 0;
        string maxWord;
        while (in >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            anagrams[sortedWord].push_back(word);

            if (anagrams[sortedWord].size() > maxLen) {
                maxLen = (int) anagrams[sortedWord].size();
                maxWord = sortedWord;
            }
        }

        cout << "maxWord=" << maxWord
        << " len=" << maxLen << endl;

        for (int j = 0; j < anagrams[maxWord].size(); ++j) {
            cout << anagrams[maxWord][j] << " ";
        }
        cout << endl;
    }

private:
    map<string, vector<string>> anagrams;

};

#endif //INC_12_HASH_ANAGRAMS_H


















