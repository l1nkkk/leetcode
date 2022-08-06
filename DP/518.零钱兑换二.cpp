//
// Created by l1nkkk on 2021/7/12.
//
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace leetcode518{
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i]:总金额为i时，最多有dp[i]组合数
        vector<int> dp(amount+1, 0);
        dp[0] = 1;

        for(int i = 0;i < coins.size(); ++i){
            for(int j = 1; j <= amount; ++j){
                if(j - coins[i] >= 0)
                    dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};

void test(){
    Solution s;
    vector<int> v{1,2,5};
    cout  << s.change(5,v);
}
}