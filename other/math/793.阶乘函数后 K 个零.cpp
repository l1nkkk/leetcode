//
// Created by l1nkkk on 2021/8/6.
//
#include <iostream>
using namespace std;
namespace leetcode793{
class Solution {
public:
    const long long MAXN = 2ll* INT32_MAX;
    int preimageSizeFZF(int k) {
        return rightFind(k) - leftFind(k) + 1;
    }
    int leftFind(int k){
        long long lo = 0;
        long long hi = MAXN;
        long long mid;
        while (lo < hi){
            mid = (hi + lo)/2;
            auto midK = trailingZeroes(mid);
            if(midK < k){
                lo = mid+1;
            } else if(midK > k){
                hi = mid;
            } else if( midK == k){
                hi = mid;
            }
        }
        return lo;
    }

    int rightFind(int k){
        long long lo = 0;
        long long hi = MAXN;
        long long mid;
        while (lo < hi){
            mid = (hi + lo)/2;
            auto midK = trailingZeroes(mid);
            if(midK < k){
                lo = mid+1;
            } else if(midK > k){
                hi = mid;
            } else if( midK == k){
                lo = mid + 1;
            }
        }
        return lo-1;
    }

    long long trailingZeroes(long long  n) {
        long long base = 5;
        long long res = 0;
        while(n / base){
            res += n / base;
            base *= 5;
        }
        return res;
    }
};

void test(){
    Solution s;
    cout  << s.preimageSizeFZF(0);
}
}