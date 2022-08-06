//
// Created by l1nkkk on 2022/4/13.
//

#include <iostream>
#include <vector>
using namespace std;
namespace offer56_1{
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 1. 设两个数分别为x和y，全部异或
        int xy = 0;
        for(auto n : nums){
            xy ^= n;
        }
        // 2. 获取 x 和 y 第一位不同的位
        int m = 1;
        while((m & xy) == 0){
            m <<= 1;
        }

        // 3. 分组异或
        int g1 = 0,g2 = 0;
        for(auto n : nums){
            if(n & m)
                g1 ^= n;
            else
                g2 ^= n;
        }
        return {g1,g2};
    }
};
}