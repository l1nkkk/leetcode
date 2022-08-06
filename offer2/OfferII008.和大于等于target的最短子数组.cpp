//
// Created by l1nkkk on 2022/6/1.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer2_8{
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lo,hi;
        lo = 0; hi = 0;
        int res = nums.size()+1;
        int now = nums[hi];
        while(hi < nums.size()-1){
            while(now >= target){
                res = res > hi-lo+1 ? hi-lo+1 : res;
                now -= nums[lo];
                ++lo;
            }

            now += nums[++hi];
        }
        while(now >= target){
            res = res > hi-lo+1 ? hi-lo+1 : res;
            now -= nums[lo];
            ++lo;
        }

        return res == nums.size()+1 ? 0 : res;
    }
};
void test(){
    Solution s;
    vector<int> input{2,3,1,2,4,3};
//    vector<int> input{1,1,1,1,1,1,1,1};
    cout << s.minSubArrayLen(7, input) << endl;
}
}