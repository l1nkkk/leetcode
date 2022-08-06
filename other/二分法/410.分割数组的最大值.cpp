//
// Created by l1nkkk on 2022/3/17.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode410{
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        auto start = getMax(nums);
        auto end = getSum(nums)+1;

        int lo = start;
        int hi = end;

        // 神奇的一点是，最后趋近的那个整数，是一个子数组和
        // [lo,hi)
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            auto n = split(nums, mid);
            // 保证只要hi变过
            // 需要 hi 尽量靠左，因为求得的结果要尽可能小
            if(n == m){
                hi = mid;
            }else if( n > m){
                // 由于 split 是单调减的，此时n过大，自变量应该变大，使得n变小
                lo = mid+1;
            }else if( n < m){
                hi = mid;
            }
        }
        return hi;
    }

    // 给定最大的子数组和，返回最少可以分割成几份
    // maxMin 越大，return 越小，单调减性质
    int split(vector<int>nums, int maxMin){
        int count = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(sum > maxMin){
                sum = nums[i];
                count++;
            }
        }
        return count;
    }

    int getMax(vector<int>& nums){
        int res = 0;
        for(auto a : nums){
            res = a > res ? a : res;
        }
        return res;
    }

    int getSum(vector<int>& nums){
        int res = 0;
        for(auto a : nums){
            res += a;
        }
        return res;
    }

};

void test(){
    vector<int> input{7,2,5,10,8};
    Solution s;
    cout << s.splitArray(input,2);

}


}