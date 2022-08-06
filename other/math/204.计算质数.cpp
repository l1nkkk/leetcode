//
// Created by l1nkkk on 2021/8/7.
//
#include <iostream>
#include <vector>
using namespace std;
namespace leetcode204{
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);
        // 最大数n的分解，最多也只需要看到sqrt(n)，所以遍历到sqrt(n)，就全部被填充排除了
        for(int i  = 2; i*i < n; ++i){
            if(isPrime[i])
                for(int j = i*2; j < n; j+=i){
                    isPrime[j] = false;
                }
        }

        int res = 0;
        for(int i = 2; i < n; ++i){
            if(isPrime[i])
                ++res;
        }
        return res;
    }

};

void test(){
    Solution s;
   cout << s.countPrimes(2);
}
}

