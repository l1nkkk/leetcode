//
// Created by l1nkkk on 2022/3/12.
//

#include <iostream>
#include <string>
using namespace std;


namespace leetcode125{
class Solution {
public:
    bool isPalindrome(string s) {
        // idea： 双指针
        if(s.empty()) return true;
        int lo, hi;
        lo = 0;
        hi = s.size()-1;
        while(lo < hi){
            // 只有数字和字母有效
            while(lo < hi && !isalpha(s[lo]) && !isdigit(s[lo])){
                ++lo;
            }
            while(lo < hi && !isalpha(s[hi]) && !isdigit(s[hi])){
                --hi;
            }
            if((s[lo++]|32) == (s[hi--]|32))
                continue;
            else
                return false;
        }
        return true;
    }
};

void test(){
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama");
    cout << s.isPalindrome("0P");
}
}