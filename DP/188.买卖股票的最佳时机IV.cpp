//
// Created by l1nkkk on 2021/8/13.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode188{
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(k+1, vector<int>(2,0)));
        int day = prices.size();
        int i = 0;
        int ki = 0;
        for( i = 0; i <= day; ++i){
            for( ki = 0; ki <= k; ++ki){
                if(i == 0){
                    dp[0][ki][0] = 0;
                    dp[0][ki][1] = -INT32_MAX;
                }else{
                    dp[i][ki][0] = max(dp[i-1][ki][0], dp[i-1][ki][1] + prices[i-1]);

                    if(ki != 0){
                        dp[i][ki][1] = max(dp[i-1][ki][1], dp[i-1][ki-1][0] - prices[i-1]);
                    }else{
                        dp[i][ki][1] = dp[i-1][ki][1];
                    }
                }
            }
        }
        int res;
        for(int ki = 0;ki <=k; ++ki){
            res = max(dp[day][ki][0],res);
        }
        return res;
    }
};

void test(){
    Solution s;
    vector<int> input{6,1,3,2,4,7};
    cout << s.maxProfit(2,input);
}
}
