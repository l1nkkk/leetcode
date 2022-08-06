//
// Created by l1nkkk on 3/29/21.
//

#include <vector>
#include <iostream>
using namespace std;

namespace leetcode72{
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(505, vector<int>(505,0));
        // 初始化dp
        for(int i = 0; i <= word1.length(); ++i){
            dp[i][0] = i;
        }

        for(int j = 0; j <= word2.length(); ++j){
            dp[0][j] = j;
        }
        // 自底向上，目标为dp[word1.length()][word2(length)]
        // 从左往右，从下往上
        for(int i = 1; i <= word1.length(); ++i){
            for(int j = 1; j <= word2.length(); ++j){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    // dp[i-1][j-1] 替换
                    // dp[i][j-1] 插入
                    // dp[i-1][j] 删除
                    dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i][j-1],dp[i-1][j]))+1;
                }
            }
        }
        return dp[word1.length()][word2.length()];

    }
};

void test(){
    Solution s;
    cout << s.minDistance("","a");
}
}