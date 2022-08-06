//
// Created by l1nkkk on 2021/8/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace leetcode1288{
bool cmp(const vector<int>& a, const vector<int>&b){
    if(a[0] == b[0]){
        return b[1] < a[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int left = intervals[0][0];
        int right = intervals[0][1];
        int res = 0;

        for(int i = 1; i < intervals.size(); ++i){
            // 情况1.覆盖
            if(intervals[i][1] <= right){
                ++res;
            }else if( intervals[i][0] <=right  && intervals[i][1] > right){
                // 情况2.相交，合并
                right = intervals[i][1];
            }else{
                // 情况3.不相交
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        return intervals.size()-res;
    }
};


void test(){
    Solution s;
    vector<vector<int>> input{{1,4},{3,6},{2,8}};
    cout << s.removeCoveredIntervals(input);

}
}