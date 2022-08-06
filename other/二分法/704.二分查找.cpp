//
// Created by l1nkkk on 2021/7/8.
//
#include <vector>
#include <iostream>
using namespace std;
namespace leetcode704{
    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left, right, mid;
            left = 0;
            right = nums.size();
            while(left < right){
                mid = left + (right - left)/2;
                if(nums[mid] == target ){
                    return mid;
                } else if( nums[mid] < target ){
                    left  = mid + 1;
                } else if( nums[mid] > target ){
                    right = mid;
                }
            }
            return -1;
        }
    };
    void test(){
        vector<int > nums{-1,0,3,5,9,12};
        Solution s;
        std::cout << s.search(nums, 9);
    }
}