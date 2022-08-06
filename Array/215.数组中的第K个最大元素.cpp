//
// Created by l1nkkk on 2021/8/9.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace leetcode215{
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0;
        int hi = nums.size()-1;
        int p;
        while(lo <= hi){
            p = partition(nums, lo, hi);
            if(k > p+1){
                lo = p+1;
            }else if(k < p+1){
                hi = p-1;
            }else{
                return nums[p];
            }
        }
        return nums[p];

    }
    int partition(vector<int>&nums, int lo, int hi){
        int i,j;
        i = lo;
        j = hi;
        int k = nums[lo];
        while(i < j){
            while(i < j && nums[j] <= k){
                --j;
            }
            if(i < j){
                nums[i++] = nums[j];
            }

            while(i < j && nums[i] > k){
                ++i;
            }
            if(i < j){
                nums[j--] = nums[i];
            }
        }
        nums[i] = k;
        return i;
    }
};
void test(){
    vector<int> input{3,2,3,1,2,4,5,5,6};
//    vector<int> input{3,2,1,5,6,4};
    Solution s;
    cout << s.findKthLargest(input,4);
}

}
