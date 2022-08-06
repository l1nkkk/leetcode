//
// Created by l1nkkk on 2021/8/6.
//
#include <iostream>
namespace leetcode191 {
    class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int i;
            int res = 0;
            while (n != 0) {
                n &= (n - 1);
                ++res;
            }
            return res;
        }
    };
}