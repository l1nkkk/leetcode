//
// Created by l1nkkk on 2021/7/26.
//
#include <vector>
#include <iostream>
using namespace std;

namespace leetcode283{
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast, slow;
        fast = 0;
        slow = 0;
        while(fast < nums.size()){
            if(nums[fast] != 0){
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        while(slow < nums.size()){
            nums[slow++]  = 0;
        }

        return;
    }
};
}