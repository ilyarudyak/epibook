#include <iostream>
#include <vector>
#include "NearestRepetition.h"
#include <boost/algorithm/string/join.hpp>
#include "PairUsers.h"
#include "Anagrams.h"

int main() {

    // 12.7 anagrams
    fstream in("words");
    Anagram anagram(in);


    // 12.5 pair users by attributes
//    vector<User> users = {
//            User(1, vector<string>{"a", "c", "d"}),
//            User(2, vector<string>{"a", "b", "c"}),
//            User(3, vector<string>{"a", "c", "e"}),
//            User(4, vector<string>{"a", "b", "c"})
//    };

//    for (int j = 0; j < users.size(); ++j) {
//        cout << users[j].getPrefs() << " ";
//    }
//    cout << endl;

//    PairUsers pu(users);
//    pu.pairUsers();

//    vector<string> elems = {"a", "b", "c"};
//    string delim = "";
//    string joinedString = boost::algorithm::join(elems, delim);
//    cout << joinedString << endl;


    // 12.3 nearest repetition
//    vector<string> words = {"all", "work", "work", "and", "no", "play",
//    "makes", "for", "no", "work", "no", "fun", "and", "no", "results"};
//
//    NearestRepetition nr(words);
//    nr.closestWord();

    return 0;
}