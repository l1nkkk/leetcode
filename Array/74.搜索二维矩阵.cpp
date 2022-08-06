//
// Created by l1nkkk on 2021/11/12.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode74{
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int x, y;
        x = matrix.size()-1;
        y = 0;
        while(x >= 0 && y < matrix[0].size() ){
            if(matrix[x][y] < target){
                ++y;
            }else if(matrix[x][y] > target){
                ++x;
            }else{
                return true;
            }
        }
        return false;

    }
};
}