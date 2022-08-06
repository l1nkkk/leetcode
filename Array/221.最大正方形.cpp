//
// Created by l1nkkk on 2021/10/5.
//

#include <iostream>
#include <vector>
using namespace std;
namespace leetcode221{
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j]:以matrix[i-1][j-1]为右下角，所能达到的最大正方形边长
        vector<vector<int>>  dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == '0')
                    continue;
                else{
                    dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j])+1;
                    if(res < dp[i+1][j+1]) res = dp[i+1][j+1];
                }
            }
        }
        return res*res;
    }
};

void test(){
    vector<vector<int>> input{{}};
}
}