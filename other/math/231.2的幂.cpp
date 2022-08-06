//
// Created by l1nkkk on 2021/8/6.
//
#include <iostream>

using namespace std;
namespace leetcode231{
    class Solution {
    public:
        bool isPowerOfTwo(int n) {
            if (n <= 0) return false;
            n &= (n - 1);
            if (n == 0)
                return true;
            return false;
        }
    };
}