//
// Created by Ilya Rudyak on 5/22/16.
//

#ifndef INC_12_HASH_LETTERFREQ_H
#define INC_12_HASH_LETTERFREQ_H

#include <map>
#include <fstream>

using namespace std;

class LetterFreq {

public:
    LetterFreq(fstream &lin) {

        string line;
        while (getline(lin, line)) {
            addFreq(line);
        }
    }

    bool isSufficient(fstream &min) {
        string line;
        while (getline(min, line)) {
            removeLine(line);
            if (letterFreq.empty()) {
                return true;
            }
        }
        return false;
    }

private:
    map<char, int> letterFreq;
    void addFreq(const string &line) {
        for (int i = 0; i < line.size(); ++i) {
            char ch = line[i];
            if (ch != ' ') {
                letterFreq[ch]++;
            }
        }
    }
    void removeLine(const string &line) {
        for (int i = 0; i < line.size(); ++i) {
            char ch = line[i];
            if (ch != ' ') {
                if (letterFreq.count(ch) > 0) {
                    if (letterFreq[ch] > 1) {
                        letterFreq[ch]--;
                    } else {
                        letterFreq.erase(ch);
                    }
                }
            }
        }
    }

};

#endif //INC_12_HASH_LETTERFREQ_H
