//
// Created by l1nkkk on 4/3/21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace leetcode10{
class Solution {
public:
    bool isMatch(string s, string p) {
        int sp = 0, pp = 0;
        while(sp < s.length() && pp < p.length()){
            // "aab" "c*a*b"
            if(s[sp] == p[pp] || p[pp] == '.'){
                ++sp;
                ++pp;
            }
            else if ( pp+1 < p.length() && p[pp+1] == '*' ){
                pp+=2;
            }
            else if (p[pp] == '*'){
                // 消灭连续的.*
                while(pp+2 < p.length() && p[pp+1] == '.' && p[pp+2] == '*'){
                    pp += 2;
                }

                // 如果前一个是. 那么就呜呜呜
                if (p[pp - 1] == '.'){
                    // 如果最后一个了
                    if(pp +1 == p.length())
                        return true;
                    // 递归
                    while(sp < s.length() && pp < p.length()){
                        if (isMatch(s.substr(sp), p.substr(pp+1)))
                            return true;
                        ++sp;
                    }

                }
                else {
                    // 如果不是
                    while (sp < s.length() && s[sp] == p[pp - 1])
                        ++sp;
                    pp = p.find_first_not_of(p[pp-1], pp+1);
                    if(p.npos == pp)
                        pp = s.length();
                }
            }
            else{
                return false;
            }
        }
        if(sp == s.length() && pp == p.length())
            return true;
        return false;
    }
};

void test(){
    Solution s;
    cout << s.isMatch("aaa","ab*a*c*a");
}
}