//
// Created by l1nkkk on 2021/8/24.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode912{


class Solution {
public:
    int getMidPar(vector<int>& nums, int lo, int hi){
        auto a = nums[lo];
        auto b = nums[hi];
        auto c = nums[(lo+hi)/2];
        if(a >= b && b >= c){   // b是中位数
            swap(nums[lo], nums[hi]);
        } else if(b >= c && c >= a){    // c是中位数
            swap(nums[lo], nums[(lo+hi)/2]);
        }
        // a是中位数
        return nums[lo];
    }

    // [lo, hi]
    int partition(vector<int>& nums, int lo, int hi){
        auto target = getMidPar(nums, lo, hi);
        while(lo < hi){
            while(lo < hi && nums[hi] >= target){
                --hi;
            }
            if(lo >= hi)
                break;
            nums[lo++] = nums[hi];

            while(lo < hi && nums[lo] < target){
                ++lo;
            }
            if(lo >= hi)
                break;
            nums[hi--] = nums[lo];
        }
        nums[lo] = target;
        return lo;
    }
    void sort(vector<int> &nums, int lo, int hi){
        if(lo >= hi) return;
        auto p = partition(nums, lo, hi);
        sort(nums, lo, p-1);
        sort(nums, p+1, hi);
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
    }
};

void test(){
    vector<int> input = {-1,2,-8,-10};
    Solution s;
    auto res =s.sortArray(input);
    for(auto a : res){
        cout << a <<" ";
    }
}

}