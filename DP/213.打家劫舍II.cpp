//
// Created by l1nkkk on 2021/8/29.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode213{
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(robRange(nums, 0, nums.size()-2), robRange(nums, 1, nums.size()-1));
    }
    int robRange(vector<int>& nums, int start, int end){
        int dpi1 = 0, dpi2 = 0;
        int dp = 0;
        for(int i = end; i >= start; --i){
            dp = max(dpi1, dpi2 + nums[i]);
            dpi2 = dpi1;
            dpi1 = dp;
        }
        return dp;

    }
};
}