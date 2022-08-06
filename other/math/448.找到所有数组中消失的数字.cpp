//
// Created by l1nkkk on 2021/8/7.
//

#include <iostream>
#include <vector>
using namespace std;
namespace leetcode448{
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> temp(nums.size()+1, 0);
        for(int i = 0; i <nums.size(); ++i){
            temp[nums[i]] = nums[i];
        }
        vector<int> res;
        for(int i = 1; i <= nums.size();++i){
            if(temp[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};
void test(){
    Solution s;
    vector<int> input{4,3,2,7,8,2,3,1};
    auto res = s.findDisappearedNumbers(input);
    for( auto r : res){
        cout <<r <<" ";
    }

}

}