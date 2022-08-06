//
// Created by l1nkkk on 2022/3/16.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode1109{
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        diff_.resize(n,0);
        vector<int> res(n,0);
        // 构建差分数组
        for(int i = 0; i < bookings.size(); ++i){
            diff_[bookings[i][0]-1] += bookings[i][2];
            if(bookings[i][1] < n)
                diff_[bookings[i][1]] -= bookings[i][2];
        }

        // 复原数组
        res[0] = diff_[0];
        for(int i = 1; i < n; ++i){
            res[i] = res[i-1]+diff_[i];
        }
        return res;
    }

private:
    vector<int> diff_;

};


void test(){
    vector<vector<int> > input{
            {1,2,10},
            {2,3,20},
            {2,5,25}
    };
    Solution s;
    auto res = s.corpFlightBookings(input, 5);
    for(auto a : res){
        cout << a << " ";
    }
}
}
