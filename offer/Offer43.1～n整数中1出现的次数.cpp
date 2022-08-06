//
// Created by l1nkkk on 2022/3/29.
//
#include <iostream>
#include <vector>
using namespace std;

namespace offer43{
class Solution {
public:
    int countDigitOne(int n) {
        int digit = 1;
        int high = n / 10, cur = n % 10, low = 0;
        int res = 0;
        while(high != 0 || cur != 0){
            if(cur == 0) res = res + high*digit ;
            else if(cur == 1)  res = res + high*digit + low + 1;
            else res = res + (high+1) *digit;

            low = cur*digit + low;
            cur = high %10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};
}

