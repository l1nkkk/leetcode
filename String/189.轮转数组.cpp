//
// Created by l1nkkk on 2022/3/12.
//
#include <iostream>
#include <vector>
using namespace std;


namespace leetcode189{
class Solution {
public:
//    [lo,hi)
    void reverse(vector<int>& nums, int lo, int hi){
        while(lo+1 < hi){
            nums[lo] ^= nums[hi-1];
            nums[hi-1] ^= nums[lo];
            nums[lo] ^= nums[hi-1];
            lo++;
            hi--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        reverse(nums,0, nums.size());
        k = k %nums.size();

        reverse(nums,0,k);
        reverse(nums, k, nums.size());
    }
};

void test(){
    Solution s;
//    vector<int> input{1,2,3,4,5,6,7};
    vector<int> input{-1,-100,3,99};
    s.rotate(input,2);
    for( auto a : input){
        cout << a << " ";
    }
}

}
