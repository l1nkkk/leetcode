//
// Created by l1nkkk on 2022/3/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


namespace leetcode435{
class Solution {
public:
    struct cmp{
        bool operator () (vector<int> &a, vector<int> b){
            return a[1] < b[1];
        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int res = 0;    // 记录当前未相交集合有多少个，因为可能剔除的很多，如果记录剔除数，会比较慢
        int i = 0;

        while(i < intervals.size()){
            ++res;
            int j = i+1;
            while(j < intervals.size() && intervals[i][1] > intervals[j][0])
                ++j;
            i = j;
        }
        return intervals.size()-res;
    }
};

void test(){
    vector<vector<int>> input{{1,2},{2,3},{3,4},{1,3}};
    Solution s;
    cout << s.eraseOverlapIntervals(input);
}

}