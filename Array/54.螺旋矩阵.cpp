//
// Created by l1nkkk on 2021/8/23.
//

#include <iostream>
#include <vector>

using namespace std;

namespace leetcode54{
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int u = 0;
        int r = matrix[0].size()-1;
        int b = matrix.size()-1;
        int l = 0;
        int i = 0, j = 0;
        while(u <= b && l <= r){
            // 左---》右
            for(int i = u,j = l; j <= r;++j){
                res.push_back(matrix[i][j]);
            }
            if(++u > b) break;

            // 上---》下
            for(int i = u, j = r; i <= b; ++i){
                res.push_back(matrix[i][j]);
            }
            if(--r < l) break;

            // 右----》左
            for(int i = b, j = r; j >= l; --j){
                res.push_back(matrix[i][j]);
            }
            if(--b < u) break;

            // 下---》上
            for(int i = b, j = l; i >= u; --i){
                res.push_back(matrix[i][j]);
            }
            if(++l > r) break;
        }
        return res;
    }
};
void test(){
    vector<vector<int>> input{{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    auto res = s.spiralOrder(input);
    cout << "test";

}
}