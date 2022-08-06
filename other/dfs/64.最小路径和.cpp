//
// Created by l1nkkk on 2021/10/4.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace leetcode64{
class Solution {
public:
    int minres = -1;
    int dist[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int minPathSum(vector<vector<int>>& grid) {
        return dpdeal(grid);
    }

    // 法2：dp
    int dpdeal(vector<vector<int>> &grid){
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1, 500001));
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(i==0 && j == 0){
                    dp[i+1][j+1] = grid[i][j];
                }else{
                    dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]) + grid[i][j];
                }
            }
        }
        return dp[grid.size()][grid[0].size()];
    }

    // 法1：dfs，超时
    void dfs(vector<vector<int>>& grid, int x, int y, int res){
        if(minres != -1 && res > minres)
            return;
        if((x == (grid.size()-1)) && (y == (grid[0].size()-1))){
            if(minres == -1){
                minres = res;
            }else{
                minres = min(minres, res);
            }
        }

        for(int i = 0; i < 4; ++i){
            int posx = x + dist[i][0];
            int posy = y + dist[i][1];
            if(check(grid, posx, posy)){

                int t = grid[posx][posy] ;
                grid[posx][posy] = -1;
                dfs(grid, posx, posy, res + t);
                grid[posx][posy] =  t;
            }
        }
    }
    bool check(vector<vector<int>>grid, int x, int y){
        if(x >= grid.size())
            return false;
        if(y >= grid[0].size())
            return false;

        return grid[x][y] >= 0;
    }
};

void test(){
//    vector<vector<int>> input{{0,0},{0,0}};
    vector<vector<int>> input{{1,3,1},{1,5,1},{4,2,1}};
    Solution s;
    cout << s.minPathSum(input);
}
}
