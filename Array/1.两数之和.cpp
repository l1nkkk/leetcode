//
// Created by l1nkkk on 2021/7/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
namespace leetcode1{
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> emap;
        for(int i = 0; i < nums.size(); ++i){
            if(emap.find(target - nums[i]) != emap.end())
                return {emap[target-nums[i]], i};
            emap[nums[i]] = i;
        }
        return {};
    }
};
}