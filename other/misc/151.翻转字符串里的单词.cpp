//
// Created by l1nkkk on 2021/9/11.
//
#include <list>
#include <string>
#include <iostream>
using namespace std;
namespace leetcode151{
class Solution {
public:
    string reverseWords(string s) {
        list<string> temp;
        int fast,slow;
        slow = 0;
        fast = 0;
        // 1.按单词拆开
        while(fast < s.size()){
            if(s[fast] == ' ' && s[fast] == s[slow]){
                while(s[fast] == ' ' && s[fast] == s[slow]){
                    ++fast;
                    slow = fast;
                }
            }else if(s[fast] == ' '){
                temp.push_back(s.substr(slow, fast- slow));
                ++fast;
                slow = fast;
            }else{
                ++fast;
            }
        }
        // 补丁
        if(fast != slow){
            temp.push_back(s.substr(slow, fast));
        }
        // 2.拼接
        string res = temp.back();
        temp.pop_back();
        while(!temp.empty()){
            auto ts = temp.back();
            temp.pop_back();
            res += " " + ts;
        }
        return res;

    }
};

void test(){
    Solution s;
    cout << s.reverseWords("the sky is blue") << endl;
}
}