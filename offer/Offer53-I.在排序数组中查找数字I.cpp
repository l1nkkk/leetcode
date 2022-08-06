//
// Created by l1nkkk on 2022/4/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace offer53_1{

int binary_left(vector<int>& nums, int target){
    int lo = 0;
    int hi = nums.size();
    while(lo < hi){
        int mid = (lo + hi)/2;
        if(nums[mid] == target){
            hi = mid;
        }else if( nums[mid] < target){
            lo = mid+1;
        }else if( nums[mid] > target){
            hi = mid;
        }
    }
    return hi;

}
int binary_right(vector<int>& nums, int target){
    int lo = 0;
    int hi = nums.size();
    while(lo < hi){
        int mid = (lo + hi)/2;
        if(nums[mid] == target){
            lo = mid+1;
        }else if( nums[mid] < target){
            lo = mid+1;
        }else if( nums[mid] > target){
            hi = mid;
        }
    }
    return hi;
}


class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_right(nums, target) - binary_left(nums,target);
    }
};

void test(){
    vector<int> input{5,7,7,8,8,10};
    Solution s;
    cout << s.search(input, 8) << endl;
}
}