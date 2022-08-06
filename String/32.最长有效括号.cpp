//
// Created by l1nkkk on 2021/10/4.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace leetcode32{
class Solution {
public:
    int longestValidParentheses(string s) {
        int slow, fast;
        slow = 0;
        fast = 0;

        int valid = 0;
        int res = 0;
        while(fast < s.size()){
            if(s[fast++] == '(')
                valid++;
            else
                valid--;
            if(valid < 0){
                slow = fast;
                valid = 0;
            } else if(valid == 0){
                res = fast-slow;
            }
        }

        slow = s.size()-1;
        fast = s.size()-1;
        valid = 0;
        while(fast >= 0){
            if(s[fast--] == ')')
                valid++;
            else
                valid--;
            if(valid < 0){
                slow = fast;
                valid = 0;
            } else if(valid == 0){
                res = slow-fast;
            }
        }

        return res;
    }
};

void test(){
    Solution s;
    cout << s.longestValidParentheses("()(()");
}
}
