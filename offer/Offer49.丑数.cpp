//
// Created by l1nkkk on 2022/4/10.
//

#include <iostream>
#include <vector>
using namespace std;


namespace offer49{
    class Solution {
    public:
        int nthUglyNumber(int n) {
            int a, b, c;
            vector<int> dp(n+1);
            a = 1; b = 1; c = 1;
            dp[1] = 1;
            int i = 2;
            while(i <= n){
                int next = min(min(dp[a] * 2, dp[b] * 3),dp[c] * 5);
                dp[i] = next;
                if(dp[i] == dp[a] * 2) ++a;
                if(dp[i] == dp[b] * 3) ++b;
                if(dp[i] == dp[c] * 5) ++c;
                ++i;
            }
            return dp[n];
        }
    };
}