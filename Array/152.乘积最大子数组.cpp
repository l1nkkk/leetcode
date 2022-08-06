//
// Created by l1nkkk on 2021/11/9.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode152{
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 以前一个为结尾，能达到的最大值和最小值
        // 重点： 当前最小要分为当前是负数还是正数
        // 正数情况 ：当前最大 = max(当前值， 当前值 * 前一个结尾的最大）
        // 负数情况 : 当前最大 = max(当前值， 当前值 * 前一个结尾的最小）
        int res = nums[0];
        int amax, amin;
        amax = nums[0];
        amin = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < 0){
                // 重点：负数的时候，用前一个元素结尾的最大值 来求 当前元素结尾的最小。
                // 注意：nums[i] == -4 , amin == 3的情况，这个时候 nums[i] > amin*nums[i]
                auto t = max(amin*nums[i], nums[i]);
                amin = min(amax*nums[i], nums[i]);
                amax = t;
            }else{
                amax = max(amax*nums[i], nums[i]);
                amin = min(amin*nums[i], nums[i]);
            }
            res = max(amax, res);
        }
        return res;
    }
};
void test(){
    vector<int>input{-4,-3,-2};
//    vector<int>input{2,3,-2,4};
    Solution s;
    cout << s.maxProduct(input);

}
}