//
// Created by l1nkkk on 2021/8/23.
//

#include <string>
#include <iostream>
using namespace std;

namespace leetcode8{
class Solution {
public:
    static constexpr uint64_t minVal = 2147483648;
    static constexpr uint64_t maxVal = 2147483647;
    int myAtoi(string s) {
        int64_t res = 0;
        bool flag = true; // true表示正数

        // 1.除去前缀空格
        int pos = 0;
        while(s[pos] == ' ') ++pos;

        // 2.判断符号
        if(s[pos] == '-') { flag = false; ++pos; }
        else if(s[pos] == '+'){++pos;}

        // 3.清除前缀0
        while(s[pos] == '0'){
            ++pos;
        }


        // 4.开始读数字
        while(check(s[pos])){
            res = res *10 + s[pos]-'0';
            // 判断是否越界
            if(!flag && res > minVal){
                res = minVal;
                return -res;
            }
            else if(flag && res > maxVal){
                res = maxVal;
                return res;
            }
            ++pos;
        }
        return flag ? res : -res;

    }
    bool check(char c){
        if(c >= '0' && c<='9')
            return true;
        return false;
    }
};

void test(){
    Solution s;
    string input = "   -42";
    cout << s.myAtoi(input);
}
}