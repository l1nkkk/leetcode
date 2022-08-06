//
// Created by l1nkkk on 2021/8/25.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode31{
class Solution {
public:
    // 1.找递增
    // 2.找到了，从右到左找比该数大
    // 3.交换后反转
    void nextPermutation(vector<int>& nums) {
        // 1
        int pre,pos;
        pos = nums.size()-1;
        pre = pos-1;
        while(pre >= 0){
            if(nums[pre] < nums[pos])
                break;
            --pre;
            --pos;
        }
        if(pre >= 0){
            // 2
            int i = nums.size()-1;
            while(nums[i] <= nums[pre]){
                --i;
            }
            swap(nums[i], nums[pre]);
        }
        // 3
        for(int i = pos, j = nums.size()-1; i < j; ++i,--j){
            swap(nums[i],nums[j]);
        }
        return;
    }
};

void test(){
    vector<int> input{3,2,1};
    Solution s;
    s.nextPermutation(input);
    cout << "test";
}
}
