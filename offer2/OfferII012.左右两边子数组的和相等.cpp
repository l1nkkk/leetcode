//
// Created by l1nkkk on 2022/8/1.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer2_12{
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // init
        int leftSum = 0;
        int rightSum = -nums[0];
        for(auto n : nums){
            rightSum += n;
        }
        if(leftSum == rightSum)
            return 0;
        for(int i = 1; i < nums.size(); ++i){
            leftSum += nums[i-1];
            rightSum -= nums[i];
            if(leftSum == rightSum)
                return i;
        }
        return -1;

    }
};
}