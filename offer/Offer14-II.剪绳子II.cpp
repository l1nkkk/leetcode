//
// Created by l1nkkk on 2022/3/26.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer14{
class Solution {
public:
    pair<int64_t , int64_t>  maxPair(const pair<int64_t, int64_t> &v1, const pair<int64_t,int64_t> &v2){
        if(v1.first == v2.first){
            return  v1.second < v2.second? v2: v1;
        }else{
            return v1.first < v2.first? v2:v1;
        }
    }
    int cuttingRope(int n) {
        // value = first * 1000000007 + second
        vector<pair<int64_t,int64_t> > dp(n+1);
        dp[n] = make_pair(0,1);
        for(int i = 2; i <= n; ++i){
            pair<int64_t,int64_t> maxVal;
            for(int j = 1; i - j >= 1; ++j){
                pair<int64_t,int64_t> t(0,0);
                t.second = j*dp[i-j].second;
                t.first = dp[i-j].first * j;
                if(t.second > 1000000007){
                    t.first = t.first + dp[i-j].first + t.second / 1000000007;
                    t.second = t.second % 1000000007;
                }
                maxVal = maxPair(maxVal, maxPair(t, make_pair(0,j*(i-j))));
            }
            dp[i] = maxVal;
        }
        return dp[n].second;
    }
};
}