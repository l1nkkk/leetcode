//
// Created by l1nkkk on 12/17/20.
//
#include <iostream>
#include <map>
#include <vector>
namespace leetcode509{
    using namespace std;
    // 方法1：穷举解法
    int fib1(int n){
        if(n == 1 || n == 2)
            return 1;
        return fib1(n-1) + fib1(n-2);
    }

    // 方法2：备忘录,自顶向上
    // 一般是map或者vector
    struct fib2{
        fib2(){memo[1] = 1;memo[2] = 1;}
        map<int,int> memo;
        int operator()(int n){
            if(memo.find(n) != memo.end())
                return memo[n];
            memo[n] = this->operator()(n-1)+this->operator()(n-2);
            return memo[n];
        }

    };

    // 方法3：dp table，自底向上
    // 效率是和备忘录一样的，只是反过来了
    int fib3(int n){
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    // 方法4:dp + 状态压缩
    int fib4(int n){
        if(n == 0) return 0;
        vector<int> dp(2,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n; ++i){
            dp[i%2] = dp[(i-1)%2] + dp[i%2];
        }
        return dp[(n-1)%2];
    }

    void test(){
        cout<<fib4(4);
    }
}