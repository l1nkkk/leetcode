//
// Created by l1nkkk on 2021/10/4.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace leetcode39{
class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
    vector<int> record;
    void dfs(vector<int>& candidates, int start, int target){
        if(target < 0)
            return;
        else if(target == 0){
            res.push_back(record);
        }
        for(int i = start; i < candidates.size(); ++i){
            if(target < candidates[i]) break;
            record.push_back(candidates[i]);
            dfs(candidates, i,target-candidates[i]);
            record.pop_back();
        }
    }
};

void test(){
    vector<int> input{2,3,6,7};
    Solution s;
    auto res = s.combinationSum(input, 7);
    for(auto &x : res){
        for(auto &y : x){
            cout << y << " ";
        }
        cout << endl;
    }

}
}

