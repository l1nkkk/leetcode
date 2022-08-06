//
// Created by l1nkkk on 2022/4/14.
//
#include <iostream>
#include <vector>

using namespace std;


namespace leetcode207{
class Solution {
public:
    vector<bool> record;
    vector<bool> path;
    // 记录图中是否有环
    bool hasCycle = false;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /// 1. 生成图
        vector<vector<int>> graph(numCourses, vector<int>{});
        for(auto &p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }

        /// 2. 判断环，有环return false
        record = vector<bool>(numCourses, false);
        path = vector<bool>(numCourses, false);

        // 因为可能有多个连通量
        for(int i = 0; i < numCourses; ++i)
            traverse(graph, i);
        return !hasCycle;
    }


    // 遍历，如果遇到了当前路径记录的，返回true，表示有环
    void traverse(vector<vector<int> > &graph, int start){
        if(path[start]){
            hasCycle = true;
            return;
        }
        if(record[start] || hasCycle)
            return;

        record[start] = true;
        path[start] = true;
        for(auto n : graph[start]){
            traverse(graph, n);
        }
        path[start] = false;
        return;
    }
};

void test(){
    Solution s;
    vector<vector<int>> input{{0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}};
//    vector<vector<int>> input{{1,0}};
    cout << s.canFinish(20,input);
}
}