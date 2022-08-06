//
// Created by l1nkkk on 2022/3/16.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode1094{
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 需判断的距离区间
        int lo = trips[0][1], hi = trips[0][2];
        diff_.resize(1000+1);


        // 构造差分数组
        for(int i = 0; i < trips.size(); ++i){
            if(trips[i][1] < lo) lo = trips[i][1];
            if(trips[i][2] > hi) hi = trips[i][2];
            diff_[trips[i][1]] += trips[i][0];
            diff_[trips[i][2]] -= trips[i][0];
        }

        // 还原数组，并不需要存储，只需一个变量来迭代
        int t = diff_[lo];
        if(t > capacity) return false;
        for(int i = lo+1; i < hi+1; ++i){
            t  = t + diff_[i];
            if(t > capacity) return false;
        }
        return true;
    }
private:
    vector<int> diff_;
};

void test(){
//    vector<vector<int>> input{
//            {2,1,5},
//            {3,3,7}
//    };
//    vector<vector<int>> input2{
//            {2,1,5},
//            {3,5,7}
//    };
    vector<vector<int>> input3{
            {9,0,1},
            {3,3,7}
    };
    Solution s;
//    cout << s.carPooling(input,4) << endl;
//    cout << s.carPooling(input2,3) << endl;
    cout << s.carPooling(input3,4) << endl;
}

}
