//
// Created by l1nkkk on 2021/7/12.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace leetcode416 {
class Solution {
public:
    bool canPartition(vector<int> &nums) {

        // 计算sum
        int sum = 0;
        for_each(nums.begin(), nums.end(),[&sum](const int &ref){ sum += ref;});
        if((sum & 1) == 1) return false;

        sum = sum/2;
        // dp: 可选物品为前i个，背包容量为j,是否可以刚刚好
        vector<bool> dp(sum+1, false);
        // base case
        dp[0] = true;


        // 状态1
        for(int i = 1; i <= nums.size(); ++i){
            for(int j = sum; j > 0; --j){
                // 状态转移
                if(j - nums[i-1] < 0)
                    dp[j] = dp[j];
                else{
                    dp[j] = dp[j - nums[i-1]] | dp[j];
                }
            }
        }

        return dp[sum];
    }
};

void test(){
//    vector<int> v{1,2,3,5};
    vector<int> v{1,5,11,5};
    Solution s;
    cout << s.canPartition(v);
}

}