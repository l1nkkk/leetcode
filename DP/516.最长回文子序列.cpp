//
// Created by l1nkkk on 2021/7/11.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace leetcode516{
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int> > dp(s.length()+1, vector<int>(s.length()+1,0));
        int res = 0;
        // base case
        for(int i = 1; i <= s.length(); ++i){
            dp[i][i] = 1;
            res = 1;
        }
        int i = 1, j = 2;
        while(j <= s.length()){
            if(s[i-1] == s[j-1]){
                if(i+1 == j)
                    dp[i][j] = 2;
                else
                    dp[i][j] = dp[i+1][j-1] + 2;
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);

            }
            res = res > dp[i][j] ? res : dp[i][j];
            i++,j++;
            if(j > s.length()){
                j = 2 + (j-i) ;
                i = 1;
            }
        }
        return res;
    }
};
void test(){
    Solution s;
    cout << s.longestPalindromeSubseq("bbbab");
}
}