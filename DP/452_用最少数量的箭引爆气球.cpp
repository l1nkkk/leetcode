//
// Created by l1nkkk on 12/16/20.
//

#include <vector>
#include <algorithm>
using namespace std;
namespace leetcode452{
    struct ops{
        bool operator()(vector<int> v1,vector<int> v2){
            return v1[1] < v2[1];
        }
    };

    class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            int i = 0;
            int res = 0;
            // 找出最多的不相交区间，就是答案
            // 1.先排序
            sort(points.begin(),points.end(),ops());
            // 选择区间，并选择下一个选择的区间
            while( i < points.size() ){
                int j = i+1;
                ++res;
                // 注意是<=
                while( j < points.size() && points[j][0] <= points[i][1] ){
                    ++j;
                }
                i = j;
            }
            return res;
        }
    };
}