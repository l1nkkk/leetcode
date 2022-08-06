//
// Created by l1nkkk on 2021/7/11.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace leetcode583{
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        // 状态1
        for(int i = 0,x = 1; i < word1.size(); ++i, ++x){
            for(int j = 0, y = 1; j < word2.size(); ++j, ++y){
                if(word1[i] == word2[j])
                    dp[x][y] = dp[x-1][y-1] +1;
                else{
                    dp[x][y] = max(dp[x-1][y], dp[x][y-1]);
                }
            }
        }
        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
    }
};
}