//
// Created by l1nkkk on 2021/7/9.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode34 {
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res{-1, -1};
        {
            int left, right, mid;
            left = 0;
            right = nums.size();

            while (left < right) {
                mid = left + (right - left)/2;
                if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid;
                } else if (nums[mid] == target) {
                    right = mid;
                }
            }

            if (left == nums.size()) res[0] = -1;
            else
                res[0] = nums[left] == target ? left : -1;
        }
        {
            int left, right, mid;
            left = 0;
            right = nums.size();

            while (left < right) {
                mid = left + (right - left)/2;
                if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid;
                } else if (nums[mid] == target) {
                    left = mid + 1;
                }
            }

            if (left == 0) res[1] = -1;
            else
                res[1] = nums[left - 1] == target ? left-1 : -1;
        }
        return res;
    }


};
void test(){
    Solution s;
    vector<int> vi{};

    s.searchRange(vi,0);
}
}