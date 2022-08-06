//
// Created by l1nkkk on 2021/8/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
namespace leetcode122{
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre = 0;
        int res = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i-1] < prices[i] && pre == -1){
                pre = i-1;
            }else if(prices[i-1] > prices[i] && pre != -1){
                res += prices[i-1] - prices[pre];
                pre = -1;
            }
        }
        // 补丁,直到最后一个还是递增的情况
        if(pre != -1){
            res += prices[prices.size()-1] -  prices[pre];
        }
        return res;
    }
};

void test(){
    Solution s;
    vector<int> input{7,1,5,3,6,4};
    cout << s.maxProfit(input);
}
}