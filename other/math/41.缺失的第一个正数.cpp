//
// Created by l1nkkk on 2021/10/2.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
namespace leetcode41{
class Solution {
public:
    static constexpr int flag = 500001;
    // 思路：如果可以索引到的，将该索引对应的值变为负数。如果是0，就变-1
    int firstMissingPositive(vector<int>& nums) {
        int last = nums.size();
        for(int i = 0; i < nums.size(); ++i){
            while(nums[i] > 0 && nums[i] <= last){// 可以作为索引
                int t = nums[i]-1;
                if(nums[t] == flag) break;
                else{
                    nums[i] = flag;
                    swap(nums, i, t);
                }
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] !=  flag){
                return i+1;
            }
        }
        return nums.size()+1;
    }
    void swap(vector<int> &nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

};

void test(){
    Solution s;
//    vector<int> input{7,8,9,11,12};
    vector<int> input{1,1};
    cout << s.firstMissingPositive(input);
}
}