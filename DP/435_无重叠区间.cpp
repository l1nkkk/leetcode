//
// Created by l1nkkk on 12/16/20.
//
#include <vector>
#include <algorithm>
#include <iostream>
namespace leetcode415{
    using namespace std;

    struct dealOper {
        bool operator()(vector<int> v1, vector<int> v2) {
            return v1[1] < v2[1];
        }
    };

    class Solution {
    public:
        // 算最多有多少个不相交的
        int eraseOverlapIntervals(vector<vector<int>> &intervals) {
            int i = 0;
            int res = 0;
            // 1.对其进行排序，按结束时间升序π
            sort(intervals.begin(), intervals.end(), dealOper());

            //for_each(intervals.begin(), intervals.end(),[](vector<int> t){
            //    cout << t[0] <<  " " << t[1] << endl;
            //});

            // 2.
            while (i < intervals.size()) {
                int j = i + 1;
                ++res;
                while (j < intervals.size() && intervals[j][0] < intervals[i][1])
                    j++;
                i = j;
            }
            return intervals.size() - res;
        }
    };

    void test(){
        Solution s;
        auto v = vector<vector<int>>({{1,2}, {2,3}, {3,4}, {1,3}});
        cout << s.eraseOverlapIntervals(v);
    }
}

