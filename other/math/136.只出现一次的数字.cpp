//
// Created by l1nkkk on 2021/8/6.
//
#include <vector>
using namespace std;
namespace leetcode136{
    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int res;
            for (auto v : nums) {
                res ^= v;
            }
            return res;
        }
    };
}