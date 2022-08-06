//
// Created by l1nkkk on 2021/7/11.
//

#include <vector>
#include <iostream>
#include <string>
using namespace  std;

namespace leetcode712{
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int> > dp(s1.length()+1, vector<int >(s2.length()+1, 0));
        // base case
        for( int x = 1; x <= s1.length(); ++x){
            dp[x][0] = dp[x-1][0] + s1[x-1];
        }
        for( int y = 1; y <= s2.length(); ++y){
            dp[0][y] = dp[0][y-1] + s2[y-1];
        }


        for(int i = 0, x = 1; i < s1.length(); ++i, ++x){
            for(int j = 0, y = 1; j < s2.length(); ++j, ++y){
                if (s1[i] == s2[j])
                    dp[x][y] = min(dp[x-1][y-1], min(dp[x-1][y] + s1[i], dp[x][y-1] + s2[j]));
                else
                    dp[x][y] = min(dp[x-1][y] + s1[i], dp[x][y-1] + s2[j]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
};

void test(){
    Solution s;
    cout << s.minimumDeleteSum("sea","eat");
}

}