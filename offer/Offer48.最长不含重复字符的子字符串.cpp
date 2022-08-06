//
// Created by l1nkkk on 2022/4/10.
//
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

namespace offer48{
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 收缩：遇到重复的收缩窗口，left = right
        // 扩张：没有重复时扩张
        // 结果：扩张中获取结果
        map<char,int> window;
        int valid;
        int res = 0;
        int left = 0;
        int right = 0;
//        ++window[s[right++]];
//        res = 1;
        while(right < s.size()){
            // 如果遇到重复
            if(window[s[right]] == 1){
                res = res < valid ? valid : res;
                while(window[left] != window[s[right]]){
                    --window[left];
                    --left;
                    --valid;
                }
            }else{
                ++window[s[right]];
                ++valid;
                ++right;
            }
        }
        res = res < window.size() ? window.size() : res;
        return res;
    }
};
}