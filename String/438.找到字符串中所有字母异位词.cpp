//
// Created by l1nkkk on 2021/7/25.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

namespace leetcode438 {
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left, right;
        vector<int> res;
        unordered_map<char, int> need, window;
        int valid = 0;

        left = 0;
        right = 0;
        for (auto it : p) {
            ++need[it];
        }

        while (right < s.size()) {
            char c = s[right];
            ++right;
            // update
            ++window[c];
            if (need.find(c) != need.end() && window[c] == need[c])
                ++valid;

            cout << "[" << left << ", " << right << "]" <<endl;
            while (need.size() == valid) {
                if (p.size() == right - left)
                    res.push_back(left);
                char c = s[left];
                ++left;
                if (need.find(c) != need.end() && window[c] == need[c]) {
                    --valid;
                }
                --window[c];
            }

        }
        return res;
    }
};

void test(){
    Solution s;
    auto res = s.findAnagrams("abab", "ab");
}

}