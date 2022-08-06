//
// Created by l1nkkk on 2021/7/9.
//
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace leetcode72_2{
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(505,vector<int>(505,1000));
        // 初始化
        for(int i = 0; i < 505; ++i){
            dp[i][0] = i;
            dp[0][i] = i;
        }
        // 状态1
        for(int i = 1; i <= word2.size(); ++i){
            // 状态2
            for(int j = 1; j <= word1.size(); ++j){
                if(word1[j-1] == word2[i-1])
                    dp[i][j] = min(dp[i-1][j-1],dp[i][j]); // 不换
                else
                    dp[i][j] = min(dp[i-1][j-1]+1,dp[i][j]); // 换
                dp[i][j] = min(dp[i][j-1]+1,dp[i][j]); // 删
                dp[i][j] = min(dp[i-1][j]+1,dp[i][j]); // 增
            }
        }
        return dp[word2.size()][word1.size()];
    }
};

void test(){
    Solution s;
    cout << s.minDistance("intention", "execution");
}
}