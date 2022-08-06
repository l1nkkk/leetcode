//
// Created by l1nkkk on 2021/8/12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace leetcode56{
bool cmp(const vector<int>& a, const vector<int>& b){
    if(a[0] == b[0]){
        return b[1] < a[1];
    }
    return a[0] < b[0];
}
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);

        int left = intervals[0][0];
        int right = intervals[0][1];
        int i;
        for(i = 1; i < intervals.size(); ++i){
            if(right >= intervals[i][1]){
                continue;
            }else if(intervals[i][0] <= right){
                right = intervals[i][1];
            }else{
                res.push_back({left,right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        if(intervals[i-1][0] <= right){
            res.push_back({left,right});
        }
        return res;
    }
};

void test(){
    Solution s;
    vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
    auto res = s.merge(input);
    cout << "test";

}

}