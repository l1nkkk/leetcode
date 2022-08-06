//
// Created by l1nkkk on 2021/11/3.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode498{
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty())
            return {};
        int m,n;
        int status = 0;
        int x,y;
        vector<int> res;
        m = mat.size();
        n = mat[0].size();
        while(status < m+n-1){
            // 奇数轮
            x = status < m-1 ? status : m-1;
            y = status - x;
            while(x >= 0 && y < n){
                res.push_back(mat[x][y]);
                --x;
                ++y;
            }
            ++status;
            if(status >= m+n-1)
                break;

            // 偶数轮
            y = status < n-1 ? status : n-1;
            x = status - y;
            while(x < m && y >= 0){
                res.push_back(mat[x][y]);
                ++x;
                --y;
            }
            ++status;
        }
        return res;
    }
};

void test(){
    Solution s;
    vector<vector<int>> input{{1,2,3},{4,5,6},{7,8,9}};
    auto res = s.findDiagonalOrder(input);
    for(auto r : res){
        cout << r << " ";
    }
}
}