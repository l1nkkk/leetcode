//
// Created by l1nkkk on 2022/3/21.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer04{
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 选取可以在两个方向中，一个递减，一个递增的点。
        int x = matrix.size()-1;
        int y = 0;

        while(x >= 0 && y < matrix[0].size()){
            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y] > target){
                --x;
            }else{
                ++y;
            }
        }
        return false;
    }
};


}