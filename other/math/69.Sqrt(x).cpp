//
// Created by l1nkkk on 2021/10/2.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

namespace leetcode69{
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        uint64_t res =  exp(0.5* log(x));
        return (res+1)*(res+1) <= x? res+1 : res;
    }
    int mySqrt1(int x) {
        int left,right;
        left = 0;
        right = x;
        // [left,right]
        while(left < right){
            uint64_t mid = left + (right - left)/2;
            uint64_t rtn=mid*mid;
            if(rtn > x){
                right = mid;
            }else
                left = mid+1;
        }
        return left-1;
    }
};

void test(){
    Solution s;
    cout << s.mySqrt1(6);
}
}