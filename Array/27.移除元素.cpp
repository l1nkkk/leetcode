//
// Created by l1nkkk on 2021/7/26.
//
#include <iostream>
#include <vector>
using namespace std;
namespace leetcode27{
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int slow, fast;
        slow = 0;
        fast = 0;
        while(fast != nums.size()){
            if(val != nums[fast]){
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow+1;
    }
};
}