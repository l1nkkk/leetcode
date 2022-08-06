//
// Created by l1nkkk on 2021/8/6.
//
#include <iostream>
using namespace std;
namespace leetcode172{
class Solution {
public:
    int trailingZeroes(int n) {
        int base = 5;
        int res = 0;
        while(n / base){
            res += n / base;
            base *= 5;
        }
        return res;
    }
};
void test(){
    Solution s;
    cout << s.trailingZeroes(125);
}
}