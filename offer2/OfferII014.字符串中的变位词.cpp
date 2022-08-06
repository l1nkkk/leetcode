//
// Created by l1nkkk on 2022/8/1.
//

#include<iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

namespace offer2_14{
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need,windows;
        int targetLen = s1.size();
        for(auto s : s1){
            ++need[s];
        }
        int left = 0;
        int right = 0;
        while(right < s2.size()){
            if(right-left == targetLen)
                return true;
            auto c = s2[right];
            ++windows[c];
            if(windows[c] > need[c]){
                while(left <= right && windows[c] != need[c]){
                    --windows[s2[left]];
                    ++left;
                }
            }
            ++right;
        }
        if(right-left == targetLen)
            return true;
        return false;
    }
};

void test(){
    Solution s;
    cout << s.checkInclusion("adc","dcda");
}
}