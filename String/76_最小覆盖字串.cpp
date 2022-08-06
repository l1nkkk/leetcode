//
// Created by l1nkkk on 4/7/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

namespace leetcode76{
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> need, window;
        int left = 0;
        int right = 0;
        int valid = 0;

        for(auto it:t)
            ++need[it];

        constexpr int MAX=1000000;
        int start,len = MAX;
        while(right < s.size()){
            char c = s[right];
            ++right;
            // 更新数据
            ++window[c];
            if(need.find(c) != need.end() && window[c] == need[c])
                ++valid;

//            cout << "[" << left << ", " << right << "]" << endl;
            while(valid == need.size()){
                // 记录结果
                if(right - left < len){
                    len = right - left;
                    start = left;
                }
                char c = s[left];
                ++left;
                // 更新数据
                if(need.find(c) != need.end() && window[c] == need[c])
                    --valid;
                --window[c];
            }
        }
        return len== MAX? "":s.substr(start, len);
    }
};

void test(){
    Solution s;
    cout <<s.minWindow( "ADOBECODEBANC", "ABC");
}
}