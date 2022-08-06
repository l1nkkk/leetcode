//
// Created by l1nkkk on 2021/10/9.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        pair<int, int> pos;
        pos.first = m-1;
        pos.second = 0;
        while(pos.first >= 0 && pos.second < n){
            if(matrix[pos.first][pos.second] < target){
                ++pos.second;
            }else if(matrix[pos.first][pos.second] > target){
                --pos.first;
            }else{
                return true;
            }
        }
        return false;
    }
};