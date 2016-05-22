//
// Created by Ilya Rudyak on 5/22/16.
//

#ifndef INC_12_HASH_PALINDROME_H
#define INC_12_HASH_PALINDROME_H

#include <string>
#include <map>
using namespace std;

class Palindrome {
public:

    Palindrome(const string &word) : word(word) {
        for (int i = 0; i < word.size(); ++i) {
            letterFreq[word[i]]++;
        }
    }
    bool isPermToPalindrome() {
        int oddFreq = 0;
        for (auto letter : letterFreq) {
            if (letter.second % 2 != 0) {
                oddFreq++;
            }
        }
        return oddFreq <= 1;
    }

private:
    string word;
    map<char, int> letterFreq;
};

#endif //INC_12_HASH_PALINDROME_H
