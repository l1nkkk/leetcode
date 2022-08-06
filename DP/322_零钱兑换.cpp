//
// Created by l1nkkk on 12/17/20.
//
#include <vector>
#include <iostream>
#include <map>
namespace leetcode322{
    using namespace std;
    // 方法1：穷举
    int coinChange1(const vector<int>& coins, int amount){

        int res = -1;
        int subProblem;
        if(amount < 0) return -1;
        else if(amount == 0) return 0;
        for(auto i:coins){
            subProblem = coinChange1(coins,amount-i);
            if(subProblem == -1) continue;
            if(res == -1)
                res = subProblem+1;
            else
                res = min(subProblem+1,res);
        }
        return res;
    }

    // 方法2：备忘录
    map<int,int> memo;
    int coinChange2(const vector<int>& coins, int amount){
        int res = -1;
        int subProblem;
        if(amount < 0) return -1;
        for(auto i:coins){
            if(memo.find(amount-i) != memo.end())
                subProblem = memo[amount-i];
            else
                subProblem = coinChange1(coins,amount-i);
            if(subProblem == -1) continue;
            if(res == -1) res = subProblem+1;
            else res = min(subProblem+1,res);
        }
        return res;
    }

    // 方法3：DP table 自底向上,这个时候因为不是递归，可以保存最终想要，所以初始化可以变一个值
    int coinChange3(const vector<int>& coins, int amount){
        vector<int> dp(amount+1, amount+1);
        // base case
        dp[0] = 0;

        // 从amount=1开始，自底向上
        for(int i = 1;i <= amount; i++){
            // 选择状态
            for(auto c : coins){
                if(i - c < 0 ) continue;
                // 如果未被初始化过
                dp[i] = min(dp[i-c]+1,dp[i]);

            }
        }
        return dp[amount] == amount+1? -1:dp[amount];
    }

    class Solution {
    public:

        int coinChange(vector<int>& coins, int amount) {
        }
    };

    void test(){
        memo[0] = 0;
        cout << coinChange3({ 2},3);
    }
}

