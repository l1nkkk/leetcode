//
// Created by l1nkkk on 2021/10/9.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace leetcode695{
class Solution {
public:
    inline bool check(vector<vector<int>>& grid, int x, int y){
        if((x >= 0 && x < grid.size()) && (y >= 0 && y < grid[0].size())){
            if(grid[x][y] == 1){
                return true;
            }
        }
        return false;
    }

    int count(vector<vector<int>>& grid, pair<int, int> pos){
        queue<pair<int, int>> record;
        record.push(pos);
        int res = 0;
        int dict[4][2] {{0,1},{0,-1},{1,0},{-1,0}};
        grid[pos.first][pos.second] = 0;
        while(!record.empty()){
            ++res;
            auto dot = record.front();
            record.pop();
            for(auto &a : dict){
                if(check(grid, dot.first + a[0], dot.second + a[1])){
                    record.push({dot.first + a[0], dot.second + a[1]});
                    grid[dot.first + a[0]][dot.second + a[1]] = 0;
                }
            }
        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    res = max(res, count(grid, {i,j}));

                }
            }
        }
        return res;
    }
};

void test(){
    vector<vector<int>> input{{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution s;
    cout << s.maxAreaOfIsland(input);
}

}