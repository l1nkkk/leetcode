//
// Created by l1nkkk on 2022/4/26.
//

#include<iostream>
#include <vector>
using namespace std;

namespace offer2_1{
class Solution {
public:
    int divide(int a, int b) {
        bool flag;
        long long x,y;
        if((a < 0 && b < 0) || (a > 0 && b > 0) ) flag = false;
        else flag = true;

        x = a; y = b;
        if(x < 0) x = -x;
        if(y < 0) y = -y;
        if(a == 0) return 0;

        long long lo,hi;
        lo = 0, hi = x+1;
        while(lo < hi){
            long long mid = lo + (hi-lo)/2;
//            cout << lo << " " << hi <<endl;
            auto temp = mul(mid,y);
            if( temp == x ){
                if(-mid == INT32_MIN)
                    return flag ? INT32_MIN:INT32_MAX;
                else
                    return flag? -mid :mid;
            }else if(temp < x){
                lo = mid + 1;
            }else if(temp > x){
                hi = mid;
            }
        }
        if(-(lo-1) == INT32_MIN)
        return flag ? INT32_MIN:INT32_MAX;
        else
            return flag? -(lo-1) :lo-1;
    }
    // 快速乘法(用于不让使用*), 计算a*b，必须保证 a b 都为正整数
    long long mul(long long a, long long b){
        long long res = 0;
        while(b != 0){
            if ((b & 1) == 1)
                res += a;
            a += a;
            b >>= 1;
        }
        return res;
    }
};

void test(){
    Solution s;
//    cout << s.divide(1,1);
    cout << s.divide(-2147483648,-1);
}

}