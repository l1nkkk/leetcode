//
// Created by l1nkkk on 2022/3/16.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode304{
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        // 初始化前缀矩阵
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if (i == 0 && j == 0) continue;
                else if(i == 0) matrix[i][j] = matrix[i][j-1] + matrix[i][j];
                else if(j == 0) matrix[i][j] = matrix[i-1][j] + matrix[i][j];
                else
                    matrix[i][j] = matrix[i-1][j]+matrix[i][j-1]+matrix[i][j]-matrix[i-1][j-1];
            }
        }
        matrix_ = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // 分四种情况，取决与左上角(row1,col1)的点
        if(row1 == 0 && col1 == 0) // 1. 直接和矩阵左上角重合
            return matrix_[row2][col2];
        else if(row1 == 0) // 2. 左上角在矩阵上边界
            return matrix_[row2][col2] - matrix_[row2][col1-1];
        else if(col1 == 0)  // 3. 左上角再矩阵左边界
            return matrix_[row2][col2] - matrix_[row1-1][col2];
        else{   // 其他情况
            return matrix_[row2][col2] - matrix_[row2][col1-1] - matrix_[row1-1][col2] + matrix_[row1-1][col1-1];
        }


    }

private:
    vector<vector<int>> matrix_;
};

void test(){
    vector<vector<int>> input = {
            {3,0,1,4,2},
            {5,6,3,2,1},
            {1,2,0,1,5},
            {4,1,0,1,7},
            {1,0,3,0,5}
    };
    NumMatrix n(input);
    cout << n.sumRegion(2,1,4,3) << endl;
    cout << n.sumRegion(1,1,2,2) << endl;
    cout << n.sumRegion(1,2,2,4) << endl;

    for(auto &a : input){
        for(auto &b : a){
            cout << b << " ";
        }
        cout << endl;
    }
}

}