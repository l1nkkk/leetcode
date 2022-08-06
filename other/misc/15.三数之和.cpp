//
// Created by l1nkkk on 2021/8/10.
//
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
namespace leetcode15{
class Solution {
public:
    vector<vector<int>> nSum(vector<int>& nums, int start, int end, int target, int n){
        if(n == 2){// twoSum
            int left = start, right = end-1;
            vector<vector<int> > res;
            while(left < right){
                if(nums[left] + nums[right] == target){
                    res.push_back({nums[left],nums[right]});
                    int leftn = nums[left];
                    int rightn = nums[right];

                    // 避免重复
                    while(left < right && nums[left] == leftn){
                        ++left;
                    }
                    while(left < right && nums[right] == rightn){
                        --right;
                    }
                }else if(nums[left] + nums[right] < target){
                    ++left;
                }else if(nums[left] + nums[right] > target){
                    --right;
                }
            }
            return res;
        }else{// nSum
            vector<vector<int>> res;
            set<int> record;
            // 注意i = start
            for(int i = start; i < nums.size(); ++i){
                // 避免重复
                if(record.count(nums[i])) continue;
                record.insert(nums[i]);
                auto tres = nSum(nums,i+1,nums.size(),target-nums[i],n-1);
                for( auto t : tres){
                    t.push_back(nums[i]);
                    res.push_back(t);
                }
            }
            return res;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 需要先排序
        sort(nums.begin(), nums.end());
        return nSum(nums,0 ,nums.size(),0,3);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSum(nums,0 ,nums.size(),target,4);
    }
};

void test(){
    Solution s;
    vector<int> input{1,0,-1,0,-2,2};
    auto res = s.fourSum(input,0);
    cout <<"test";
}

}