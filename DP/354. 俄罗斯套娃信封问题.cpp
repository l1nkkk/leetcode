//
// Created by l1nkkk on 2021/7/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace leetcode354{
class Solution {
public:
    static bool compare(const vector<int>& lv, const vector<int>& rv){
        if(lv[0] < rv[0]){
            return true;    // 降序
        } else if (lv[0] == rv[0]){
            return lv[1] > rv[1]; // 升序
        } else {
            return false;
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> dp(envelopes.size()+5, 1);
        for(int i = 1; i < envelopes.size(); ++i){
            int j = i-1;
            while(j >= 0){
                if( envelopes[j][1] < envelopes[i][1]){
                    if(dp[i] < dp[j]+1)
                        dp[i] = dp[j]+1;
                }
                --j;
            }
        }

        // 找最大
        int res;
        for_each(dp.begin(), dp.end(), [&res](const int &li){ res = res < li ? li : res; });
        return res;
    }
};

void test(){
    vector<vector<int>> vt = {{5,4},{6,4},{6,7},{2,3}};
    Solution s;
    std::cout << s.maxEnvelopes(vt);

}

}