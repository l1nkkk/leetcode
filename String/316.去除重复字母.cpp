//
// Created by l1nkkk on 2021/7/30.
//
#include <string>
#include <iostream>
#include <map>
#include <stack>
using namespace std;

namespace leetcode316 {
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s == "") return "";

        stack<char> stk;
        int pos = 0;
        // 初始化记录
        map<char, int> record;
        bool exist[256]{false};
        for (auto c : s) {
            ++record[c];
        }

        // 单调栈（增）
        for (int i = 0; i < s.length(); ++i) {
            if (exist[s[i]]) {
                --record[s[i]];
                continue;
            }
            while (!stk.empty() && s[i] < stk.top()) {
                if (record[stk.top()] != 0) {
                    exist[stk.top()] = false;
                    stk.pop();
                }else{
                    break;
                }
            }
            stk.push(s[i]);
            exist[s[i]] = true;
            --record[s[i]];
        }

        string rtn;
        while (!stk.empty()) {
            rtn += stk.top();
            stk.pop();
        }
        int left = 0,right = rtn.length()-1;
        while(left <right){
            auto t = rtn[right];
            rtn[right] = rtn[left];
            rtn[left] = t;
            ++left;
            --right;
        }
        return rtn;
    }
};

void test(){
    Solution s;
    cout << s.removeDuplicateLetters("cbacdcbc");
}

}