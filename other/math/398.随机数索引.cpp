//
// Created by l1nkkk on 2021/8/7.
//

#include <iostream>
#include <vector>
using namespace std;
namespace  leetcode398{
class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int p = 1;
        int res = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == target){
                // 选则当前概率
                if(rand()%p == 0){
                    res = i;
                }
                ++p;
            }
        }
        return res;
    }
};
}
