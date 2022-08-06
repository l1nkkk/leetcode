//
// Created by l1nkkk on 2022/4/14.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace leetcode210{
class Solution {
public:
    int count = 0;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        // 1. 构造图
        // 2. 计算入度
        vector<vector<int>> graph = vector<vector<int>>(numCourses,vector<int>{});
        vector<int> indegree(numCourses,0);
        for(auto p : prerequisites){
            // from to
            graph[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }

        // 3. bfs
        // init
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            ++count;
            for(auto n : graph[node]){
                --indegree[n];
                if(indegree[n] == 0)
                    q.push(n);
            }
        }

        // 4. res
        return count == numCourses ? res:vector<int>();
    }
};
}