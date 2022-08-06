//
// Created by l1nkkk on 2022/3/20.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode45{
    class Solution {
    public:
        int jump(vector<int>& nums) {
            if(nums.size() == 1) return 0;
            int fastNext = 0; // 下一跳的最远位置
            int fastCur;  // 当前跳的最远位置
            int res = 0;        // 结果
            int i = 1;          // (cur, fastCur]试探位置
            fastCur = 0 + nums[0];
            if(fastCur >= nums.size()-1)
                return res+1;
            while(i < nums.size()-1){
                if(i > fastCur){
                    // 在(cur, fastCur] 之间选择一跳
                    ++res;
                    fastCur = fastNext;
                }
                fastNext = max(fastNext,nums[i] + i);
                ++i;
                if(fastNext >= nums.size()-1){
                    // 说明再经两跳就能到达结果， cur -第一跳-> i -第二跳-> dst
                    return res+2;
                }
            }
            return res;
        }
    };
void test(){
    vector<int> input{1,1,1,1};
//    vector<int> input{2,3,1,1,4};
    Solution s;
    cout << s.jump(input);
}
}