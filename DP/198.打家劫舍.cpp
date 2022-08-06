//
// Created by l1nkkk on 2021/8/29.
//
#include <iostream>
#include <vector>
using namespace std;


namespace leetcode198{
class Solution {
public:
    int rob(vector<int>& nums) {
        int dpi1 = 0;
        int dpi2 = 0;
        int dp;
        for(int i = nums.size()-1; i >= 0; --i){
            dp = max(dpi1, dpi2 + nums[i]);
            dpi2 = dpi1;
            dpi1 = dp;
        }
        return dp;
    }
};

void test(){
    vector<int >v{1,2,3,1};
    Solution s;
    cout << s.rob(v);
}
}

