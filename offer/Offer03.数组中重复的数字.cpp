//
// Created by l1nkkk on 2022/3/21.
//

#include <iostream>
#include <vector>
using namespace std;
namespace offer3{
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == i)
                while(i < nums.size() &&nums[i] == i){
                    ++i;
                }
            else {
                while (i < nums.size() && nums[i] != i) {
                    // 原地交换
                    if (nums[i] == nums[nums[i]]) return nums[i];
                    swap(nums[i], nums[nums[i]]);
                }
                ++i;
            }
        }
        // never reach
        return 0;
    }
};

void test(){
    vector<int> input{2, 3, 1, 0, 2, 5, 3};
    Solution s;
    cout <<s.findRepeatNumber(input);
}
}