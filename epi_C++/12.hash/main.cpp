#include <iostream>
#include <vector>
#include "NearestRepetition.h"
using namespace std;

int main() {

    // 12.3 nearest repetition
    vector<string> words = {"all", "work", "work", "and", "no", "play",
    "makes", "for", "no", "work", "no", "fun", "and", "no", "results"};

    NearestRepetition nr(words);
    nr.closestWord();

    return 0;
}