//
// Created by l1nkkk on 2021/9/30.
//

#include <vector>
#include <iostream>
using namespace std;

namespace leetcode153{
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left, right;
        left = 0;
        right = nums.size()-1;
        // 注：这里返回的是一个只有一个元素的区间，这个元素就是最小的元素。这种情况最好用左闭右闭，比较简单
        while(left < right){
            int mid = left + (right - left) /2;
            if( nums[mid] < nums[right]){   // 最小值再左边
                right = mid;
            } else{ // 最小值再右边
                left = mid+1;
            }
        }
        return nums[left];
    }
};

void test(){
    vector<int> input{2,1};
    Solution s;
    cout << s.findMin(input) << endl;
}
}