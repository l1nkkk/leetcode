//
// Created by l1nkkk on 2021/8/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace leetcode986{
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // 左边取最大，右边取最小
        int left, right;
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size()){
            auto minRight = min(firstList[i][1], secondList[j][1]);
            auto maxLeft = max(firstList[i][0], secondList[j][0]);
            // 有相交
            if(minRight >= maxLeft){
                res.push_back({maxLeft, minRight});
            }
            // 更新
            if(minRight == firstList[i][1]){
                ++i;
            }else{
                ++j;
            }

        }
        return res;
    }
};

void test(){
    Solution s;
    vector<vector<int>> input1{{0,2},{5,10},{13,23},{24,25}}, input2{{1,5},{8,12},{15,24},{25,26}};
    auto res = s.intervalIntersection(input1, input2);
    cout << "test";
}

}