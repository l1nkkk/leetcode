//
// Created by l1nkkk on 2021/7/10.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

namespace leetcode53{
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int > dp(nums);
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i-1] > 0 ? dp[i-1] + dp[i] : dp[i];
        }
        int res = dp[0];
        for_each(dp.begin(), dp.end(), [&res](const int& ref){ res = res < ref ? ref : res; });
        return res;
    };
};
}