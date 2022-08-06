//
// Created by l1nkkk on 2022/4/3.
//
#include <iostream>
#include <vector>
using namespace std;

namespace leetcode797{
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    // 明确无环
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        traverse(graph, 0);
        return res;
    }
    void traverse(vector<vector<int>>& graph, int cur){
        if(cur == graph.size()-1){
            path.push_back(cur);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(cur);
        for(auto a : graph[cur]){
            traverse(graph, a);
        }
        path.pop_back();
    }

};
}