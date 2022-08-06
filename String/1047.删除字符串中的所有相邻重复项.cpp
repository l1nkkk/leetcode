//
// Created by l1nkkk on 2022/3/14.
//

#include <iostream>
#include <string>
using namespace std;


namespace leetcode1047{
class Solution {
public:
    string removeDuplicates(string s) {
        string res = s.substr(0,1);
        for(int i = 1; i < s.size(); ++i){
            if(!res.empty() && res.back() == s[i]){
                res.pop_back();
            }else
                res.push_back(s[i]);
        }
        return res;
    }
};

void test(){
    Solution s;
    cout << s.removeDuplicates("abbaca");
}
}