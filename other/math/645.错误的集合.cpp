//
// Created by l1nkkk on 2021/8/7.
//
#include <iostream>
#include <vector>
using namespace std;
namespace leetcode645{
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            int index = abs(nums[i])-1;
            if(nums[index] < 0){
                res.push_back(index+1);
                continue;
            }
            nums[index] = -nums[index];
        }

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0){
                res.push_back(i+1);
                break;
            }
        }
        return res;
    }
};
void test(){
    Solution s;
    vector<int> input{2,2};
    auto res = s.findErrorNums(input);
    cout << "tes";
}
}