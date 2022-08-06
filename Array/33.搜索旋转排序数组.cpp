//
// Created by l1nkkk on 2021/8/19.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode33{
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size();
        while(lo < hi){
            int mid = lo +(hi - lo)/2;
            if(target == nums[mid])
                return mid;
            else if(target == nums[lo])
                return lo;
            else if(target == nums[hi-1])
                return hi-1;

            if(nums[mid] > nums[lo]){
                // lo 和mid没断裂
                if(target < nums[mid] && target > nums[lo]){
                    hi = mid;
                }else{
                    lo = mid+1;
                }
            }else{
                // 断裂了
                if(target > nums[mid] && target < nums[hi-1]){
                    lo = mid+1;
                }else{
                    hi = mid;
                }
            }
        }
        return -1;
    }
};

void test(){
    Solution s;
    vector<int > input{1,3,5};
    cout << s.search(input,5) << endl;
    cout <<"test";
}
}
