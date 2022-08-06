//
// Created by l1nkkk on 2021/7/11.
//
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

namespace leetcode1143{
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        // 状态1：text1的长度
        for(int i = 0, ii = 1; i < text1.size(); ++i, ++ii){
            // 状态2： text2的长度
            for(int j = 0, jj = 1; j < text2.size(); ++j, ++jj){
                // 选择
                if(text1[i] == text2[j])
                    dp[ii][jj] = dp[ii-1][jj-1] + 1;
                else{
                    dp[ii][jj] = max(dp[ii-1][jj], dp[ii][jj-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
void test(){
    Solution s;
    cout << s.longestCommonSubsequence( "abcde","ace" );
}
}