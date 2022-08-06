//
// Created by l1nkkk on 2022/8/4.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace offer2_83{
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        res.push_back(nums);
        while(true){
            // 1. 找递增
            int i, ii;
            i = nums.size()-1;
            ii = i-1;
            while(ii >= 0 && nums[ii] >= nums[i]){
                --i;
                --ii;
            }
            if(ii < 0) break;

            // 2. 从右到左，找比nums[ii]大的数
            int x = nums.size()-1;
            while(x > ii && nums[x] <= nums[ii]){
                --x;
            }
            swap(nums[x],nums[ii]);

            // 3. 反转
            int y = nums.size()-1;
            while(i < y){
                swap(nums[i],nums[y]);
                ++i;
                --y;
            }
            res.push_back(nums);
        }
        return res;
    }
};

void test(){
    Solution s;
    vector<int> nums{1,1,2};
    auto res = s.permute(nums);
    cout <<"test";
}
}