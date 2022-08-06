//
// Created by l1nkkk on 2021/8/3.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

namespace leetcode698{
class Solution {
public:
    int avg;
    set<int> isChoose;
    vector<int> levelSum;
    int END;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 初始处理
        int sum = 0;
        int END = k;
        for_each(nums.begin(),nums.end(), [&sum](int &n){sum+=n;});
        levelSum.resize(k,0);

        // 过滤1
        if(sum%k != 0)
            return false;
        // 过滤2
        avg = sum/k;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > avg)
                return false;
        }

        return dfs(nums, 0);
    }

    bool dfs(vector<int>& nums, int level){
        if(level == END)
            return true;


        for(int i = 0; i < nums.size(); ++i){
            if(isChoose.find(i) != isChoose.end())
                continue;

            isChoose.insert(i);
            if(check(level, nums[i]) == 0){
                levelSum[level] += nums[i];
                if(dfs(nums,level+1))
                    return true;
            } else if(check(level, nums[i]) == -1){
                levelSum[level] += nums[i];
                if(dfs(nums,level))
                    return true;
            }
            isChoose.erase(i);
        }
        return false;
    }
    int check(int level, int input){
        if(levelSum[level] + input > avg)
            return 1;
        else if (levelSum[level] + input == avg){
            return 0;
        } else{
            return -1;
        }
    }

};

void test(){
    Solution s;
    vector<int> input = {2,2,2,2,3,4,5};
    auto res = s.canPartitionKSubsets(input, 4);
    cout << res;
}
}
