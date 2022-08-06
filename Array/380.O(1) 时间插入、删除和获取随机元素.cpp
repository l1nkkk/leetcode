//
// Created by l1nkkk on 2021/7/31.
//
#include <iostream>
#include <string>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;
namespace leetcode380{
class RandomizedSet {
public:
    vector<int> data;
    unordered_map<int, int> record;
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(record.find(val) != record.end())
            return false;

        data.push_back(val);
        record[val] = data.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(record.find(val) == record.end())
            return false;

        record[data.back()] = record[val];
        data[record[val]] ^= data.back();
        data.back() ^= data[record[val]];
        data[record[val]] ^= data.back();

        data.pop_back();
        record.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return data[rand()%data.size()];
    }
};
}