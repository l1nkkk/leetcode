//
// Created by l1nkkk on 2021/8/13.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode123{
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int k = 0, kend = 2;
        int res = 0;
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(3, vector<int>(2,0)));
        for(i = 0; i <= prices.size(); ++i){
            for(k = 0; k <= kend; ++k){
                if( i == 0){
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -INT32_MAX;
                }else{
                    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);
                    if(k > 0)
                        dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);
                    else
                        dp[i][k][1] = dp[i-1][k][1];
                }
            }
        }
        for(k = 0; k <= kend; ++k){
            res = max(dp.at(i-1).at(k).at(0), res);
        }
        return res;
    }
};
void test(){
    Solution s;
    vector<int> input{1};
    cout << s.maxProfit(input);
}
}