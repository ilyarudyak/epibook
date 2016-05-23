//
// Created by Ilya Rudyak on 5/22/16.
//

#ifndef INC_12_HASH_ISBNCACHE_H
#define INC_12_HASH_ISBNCACHE_H

#include <map>
#include <queue>
#include <string>
#include <fstream>
#include <time.h>
#include <iostream>

using namespace std;

class Book {
public:
    Book() = default;
    Book(const string &ISBN, int price) : ISBN(ISBN), price(price) { }


    const string &getISBN() const {
        return ISBN;
    }

    int getPrice() const {
        return price;
    }

private:
    string ISBN;
    int price;
};

class ISBNCache {

public:
    ISBNCache(fstream &in, int cacheSize) {
        string ISBN;
        int price;
        while (in >> ISBN >> price) {
            Book book(ISBN, price);
            books[ISBN] = book;
        }
        this->cacheSize = cacheSize;
    }

    void getPrice(string ISBN) {
        // if cache contains book get it from there
        if (cache.count(ISBN) > 0) {
            // update time
            cache[ISBN].second = time(nullptr);
            cout << "price=" << cache[ISBN].first.getPrice()
            << " (from cache)" << endl;

        } else { // otherwise get it from books
            if (cache.size() > 2 * cacheSize) {
                // this is lazy delete; we may also delete each element
                resizeCache();
            }
            Book book = books[ISBN];
            cache[ISBN] = make_pair(book, time(nullptr));
            cout << "price=" <<book.getPrice()
            << " (from books)" << endl;
        }
    }

private:
    map<string, Book> books;
    map<string, pair<Book, time_t>> cache;
    int cacheSize;
    // lazy delete
    void resizeCache() {
        // iterate over cache, find median
        // discard all elements below
        time_t medianTime;
        int count;
        for (auto item : cache) {
            time_t curTime = item.second.second;
            if (curTime < medianTime) {
                if (count == cacheSize) {

                }
            }
        }
    }
};

#endif //INC_12_HASH_ISBNCACHE_H
