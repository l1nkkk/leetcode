//
// Created by l1nkkk on 2021/9/30.
//
#include <iostream>
#include <vector>

using namespace std;
namespace leetcode48{
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int round = matrix.size()/2;    // 旋转圈数
        int lx,ly,rx,ry;    // 边界，左上角和左下角
        lx = 0;
        ly = 0;
        rx = matrix.size()-1;
        ry = matrix.size()-1;
        while(--round>=0){
            // 边界
            for(int i = lx, j = ly; j < ry; ++j){
                int t;
                int posx = i;
                int posy = j;
                t = matrix[posx][posy];
                int n = 4;
                // 4次
                do{
                    int pt = posx;
                    posx = posy;
                    posy = matrix.size()-1-pt;
                    matrix[posx][posy] ^= t;
                    t ^= matrix[posx][posy];
                    matrix[posx][posy] ^= t;
                    --n;
                }while(n != 0);
            }
            ++lx;
            ++ly;
            --rx;
            --ry;
        }
    }
};

void test(){
    vector<vector<int>> input{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution s;
    s.rotate(input);
    for(auto &x : input){
        for(auto &y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}
}