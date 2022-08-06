//
// Created by l1nkkk on 3/29/21.
//

#include <stack>
#include <iostream>
#include <string>
using namespace std;

namespace leetcode20{
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i =0;
        for(i = 0;i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else{
                if(st.empty()) return false;
                auto pchar = st.top();
                st.pop();
                if(s[i] == ')' && pchar == '(')
                    continue;
                else if(s[i] == '}' && pchar == '{')
                    continue;
                else if(s[i] == ']' && pchar == '[')
                    continue;
                else
                    return false;
            }
        }
        // 如果栈没空
        if(!st.empty()) return false;
        if(i == s.length())
            return true;
        return false;
    }
};

void test(){
    Solution s;
    cout << s.isValid("()");
}
}