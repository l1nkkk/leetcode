//
// Created by l1nkkk on 2022/3/26.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer29{
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return vector<int>();
        int u,l,r,b;
        int flag = 0;
        u = 0;
        l = 0;
        b = matrix.size()-1;
        r = matrix[0].size()-1;
        vector<int> res;
        while(u <= b && l <= r){
            // 左
            if(flag == 0){
                for(int i = l; i <= r; ++i){
                    res.push_back(matrix[u][i]);
                    cout << "left：" << endl;
                    cout << res.back() << " ";
                }
                flag = 1;
                ++u;
            }

            // 下
            else if(flag == 1){
                for(int i = u; i <= b; ++i){
                    res.push_back(matrix[i][r]);
                    // cout << res.back() << " ";
                }
                --r;
                flag = 2;
            }

            // 右
            else if(flag == 2) {
                for (int i = r; i >= l; --i) {
                    res.push_back(matrix[b][i]);
                    //     cout << res.back() << " ";
                }
                --b;
                flag = 3;
            }

            // 上
            else if(flag == 3) {
                for (int i = b; i >= u; --i) {
                    res.push_back(matrix[i][l]);
                    // cout << res.back() << " ";
                }
                ++l;
                flag = 1;
            }
        }
        return res;
    }
};
}