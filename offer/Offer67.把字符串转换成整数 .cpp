//
// Created by l1nkkk on 2022/4/16.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer67{
class Solution {
public:
    string trim(string &s){
        int lo = 0;
        int hi = s.size()-1;
        while(lo < s.size() && s[lo] == ' ' ) ++lo;
        while(hi >= 0 && s[hi] == ' ' ) --hi;
        return s.substr(lo, hi+1-lo);
    }
    int strToInt(string str) {
        bool flag = false; // 是否负数
        str = trim(str); // 去除空格
        if(str[0] == '-') {
            flag = true;
            str = str.substr(1);
        }else if(str[0] == '+'){
            flag = false;
            str = str.substr(1);
        }

        auto endPos = str.find_first_not_of("0123456789");
        if(endPos == 0){
            return 0;
        }
        str = str.substr(0, endPos);

        // 字符串转数字
        long long MIN = (long long)INT32_MAX + 1;
        long long MAX = INT32_MAX;
        long long res = 0;
        for(int i = 0; i < str.size(); ++i){
            res = res * 10 + str[i] - '0';
            if(flag && res >= MIN) return INT32_MIN;
            if(!flag && res >= MAX) return INT32_MAX;
        }
        return flag ? -res : res;
    }
};

void test(){
    Solution s;
//    cout << s.strToInt("42") << " ";
    cout << s.strToInt("     -42") << " ";
//    cout << s.strToInt("4193 with words") << " ";
//    cout << s.strToInt("words and 987") << " ";

}

}