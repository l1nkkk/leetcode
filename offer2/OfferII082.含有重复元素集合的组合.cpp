//
// Created by l1nkkk on 2022/8/5.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

namespace offer2_82{
class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int,int> record;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        for(auto c : candidates){
            ++record[c];
        }
        vector<int > status;
        dfs(status, candidates, 0,target);
        return res;
    }
    // 让每一层，只处理一种数，避免重复和复杂度
    void dfs(vector<int>& status,vector<int>& data, int start,int target){
        if(start == data.size() && target == 0){
            res.push_back(status);
            return;
        }
        if(start == data.size())
            return;

        if(target < data[start])return;
        for(int i = 0; i <= record[data[start]]; ++i){
            for(int j = 0;j < i; ++j){
                status.push_back(data[start]);
            }
            dfs(status,data,start+record[data[start]],target-data[start]*i);
            for(int j = 0;j < i; ++j){
                status.pop_back();
            }
        }
    }
};

void test(){
    vector<int> input{2,5,2,1,2};
    Solution s;
    auto res = s.combinationSum2(input, 5);
    cout << "res";
}
}