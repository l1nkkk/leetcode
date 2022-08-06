//
// Created by l1nkkk on 2022/3/20.
//

#include <iostream>
#include <vector>

using namespace std;

namespace leetcode55{
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fast = 0;// 记录能跳到的最远距离
        int i = 0;
        while(i < nums.size()){
            if(i > fast)
                return false;
            fast = max(fast, i+nums[i]);
        }
        return fast >= nums.size() -1;
    }
};


}