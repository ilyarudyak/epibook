//
// Created by Ilya Rudyak on 5/22/16.
//

#ifndef INC_12_HASH_PAIRUSERS_H
#define INC_12_HASH_PAIRUSERS_H

#include <vector>
#include <boost/algorithm/string/join.hpp>
using namespace std;

class User {
public:

    User() = default;

    User(int userId, vector<string> prefs) {
        this->userId = userId;
        this->prefs = prefs;
    }


    int getUserId() const {
        return userId;
    }

    const string getPrefs() const {
        return boost::algorithm::join(prefs, "");
    }

private:
    int userId;
    vector<string> prefs;
};

class PairUsers {

public:
    PairUsers(const vector<User> &users) : users(users) { }
    void pairUsers() {
        for (int i = 0; i < users.size(); ++i) {
            User curUser = users[i];
            string prefs = curUser.getPrefs();
            // there is user with *same* prefs
            if (usersMap.count(prefs) > 0) {
                User existUser = usersMap[prefs];
                pairedUsers.push_back(make_pair(existUser, curUser));
                usersMap.erase(prefs);
            } else {
                usersMap[prefs] = curUser;
            }
        }
        for (int j = 0; j < pairedUsers.size(); ++j) {
            User user0 = pairedUsers[j].first;
            User user1 = pairedUsers[j].second;
            cout << "prefs="  << user0.getPrefs()
                 << " user0=" << user0.getUserId()
                 << " user1=" << user1.getUserId();
        }
    }
private:
    vector<User> users;
    map<string, User> usersMap;
    vector<pair<User, User>> pairedUsers;

};

#endif //INC_12_HASH_PAIRUSERS_H
















