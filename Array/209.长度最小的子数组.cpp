//
// Created by l1nkkk on 2021/11/3.
//

#include <iostream>
#include <vector>
using namespace std;


namespace leetcode209{
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left = 0, right = 0;
        int cur = 0;
        int res = nums.size() + 1;
        while(right < nums.size()){
            // 左移，cur < target情况
            cur += nums[right];
            while(cur >= target){
                res = min(res, right-left+1);
                cur -= nums[left];
                ++left;
            }
            ++right;
        }
        return res == nums.size() + 1? 0 :res;
    }
};

void test(){
    Solution s;
    vector<int> input{1,2,3,4,5};
    cout << s.minSubArrayLen(11, input);

}
}
