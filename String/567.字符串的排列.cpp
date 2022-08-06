//
// Created by l1nkkk on 2021/7/25.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;


namespace leetcode567{
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left, right;
        int valid = 0;
        map<char, int> need, window;

        left = 0;
        right = 0;
        for( auto it : s1 ){
            ++need[it];
        }

        while(right < s2.size()){
            char c = s2[right];
            ++right;
            // 更新
            ++window[c];
            if(need.find(c) != need.end() && window[c] == need[c])
                ++valid;

            while(valid == need.size()){
                if(right - left == s1.size())
                    return true;
                char c = s2[left];
                ++left;
                if(need.find(c) != need.end() && window[c] == need[c])
                    --valid;
                --window[c];
            }
        }
        return false;
    }
};

void test(){
    Solution s;
    cout << s.checkInclusion("ab", "eidboaoo");
}
}
