//
// Created by l1nkkk on 2021/8/3.
//
#include <vector>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    set<int> record;
    vector<vector<int>> combine(int n, int k) {
        dfs(n,k,0, 1);
        return res;
    }

    void dfs(int n, int k, int nl, int start){
        if(nl == k){
            res.push_back(vector<int>(record.begin(), record.end()));
            return;
        }
        for(int i = start; i <= n; ++i){
            if(record.find(i) != record.end())
                continue;
            record.insert(i);
            dfs(n, k, nl+1, i);
            record.erase(i);
        }
    }
};