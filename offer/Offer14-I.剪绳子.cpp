//
// Created by l1nkkk on 2022/3/26.
//
#include <iostream>
#include <vector>

using namespace std;
//namespace offer14{
//class Solution {
//public:
//    int cuttingRope(int n) {
//        // dp[i] : 长度为 i 的绳子，所能剪成的最大长度
//        vector<int> dp(n+1);
//        dp[1] = 1;
//        for(int i = 2;i <= n; ++i){
//            // 至少要剪一次
//            int maxVal = 0;
//            for(int j = 1; i - j>=1 && j <=3; ++j){
//                maxVal = max(maxVal, max(j * dp[i-j], j *(i-j)));
//            }
//            dp[i] = maxVal;
//        }
//        return dp[n];
//
//    };
//};
//}
