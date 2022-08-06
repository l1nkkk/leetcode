//
// Created by l1nkkk on 2021/8/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace leetcode121{
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i =0;
        int k = 0;
        // 天数，可买入次数，是否持有
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(2,0)));
        for(int i = 0; i <= prices.size(); ++i){
            for(k = 0; k < 2; ++k){
                if(i == 0){
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -INT32_MAX;
                }else{
                    // 没持有状态
                    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);
                    // 持有状态
                    if(k != 0)
                        dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);
                    else
                        dp[i][k][1] = dp[i-1][k][1];
                }
            }
        }
        int res;
        res = max(dp[prices.size()][0][0],dp[prices.size()][1][0]);
        return res;
    }
};

void test(){
    Solution s;
    vector<int> input{7,1,5,3,6,4};
    cout << s.maxProfit(input);
}
}