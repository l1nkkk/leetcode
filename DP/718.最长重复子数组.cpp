//
// Created by l1nkkk on 2021/10/4.
//
#include <iostream>
#include <vector>
using namespace std;

namespace leetcode718{
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1,0));
        int max = 0;
        for(int i = 1; i <= nums1.size(); ++i){
            for(int j = 1; j <= nums2.size(); ++j){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                    if(dp[i][j] > max) max = dp[i][j];
                }
            }
        }
        return max;
    }
};

}