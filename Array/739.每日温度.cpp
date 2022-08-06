//
// Created by l1nkkk on 2021/8/10.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

namespace leetcode739{
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> res(t.size(), 0);
        stack<int> stk; // 存放索引
        for(int i = 0; i < t.size(); ++i){
            while(!stk.empty() && t[stk.top()] < t[i]){
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
    }
};

void test(){
    Solution s;
    vector<int> input{73,74,75,71,69,72,76,73};
    auto res = s.dailyTemperatures(input);
    cout << "test";
}
}