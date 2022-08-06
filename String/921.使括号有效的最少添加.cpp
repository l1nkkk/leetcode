//
// Created by l1nkkk on 2021/8/11.
//

#include <iostream>
#include <string>
using namespace std;

namespace leetcode921{
class Solution {
public:
    int minAddToMakeValid(string s) {
        int need=0;
        int res = 0;
        for(int i = 0; i <s.size();++i){
            if(s[i] == '('){
                ++need;
            }else if(s[i] == ')'){
                --need;
                if(need == -1){
                    ++res;
                    need = 0;
                }
            }
        }
        if(need > 0)
            res += need;
        return res;
    }
};
void test(){
    Solution s;
    cout <<s.minAddToMakeValid("()))((");
}
}