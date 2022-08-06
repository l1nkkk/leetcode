//
// Created by l1nkkk on 2022/8/4.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace offer2_81{
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> status;
        dfs(status, candidates, 0, target);
        return res;
    }
    void dfs(vector<int>& status,vector<int>&candidates, int start ,int target){
        if(target == 0){
            res.push_back(status);
        }
        for(int i = start; i < candidates.size(); ++i){
            if(target < candidates[i]) return;
            status.push_back(candidates[i]);
            dfs(status, candidates, i, target-candidates[i]);
            status.pop_back();
        }
    }
};
}