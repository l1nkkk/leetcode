//
// Created by l1nkkk on 2022/4/3.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace leetcode1514{
class Solution {
public:
    struct  State{
        int vertex;
        double prob;
        State(int v, double p): vertex(v), prob(p){}
    };
    struct cmp{
        bool operator()(State &s1, State &s2){ return s1.prob < s2.prob;}
    };

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        /// 1. 初始化
        // 初始化图
        vector<vector<pair<int, double>>> graph(n);
        for(int i = 0; i < edges.size(); ++i){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        // 初始化 record， record[i]记录start 到 i 的最大概率
        vector<double> record(n,0);

        /// 2. dijkstra
        priority_queue<State, vector<State>, cmp> pqs;
        pqs.push({start,1});
        while (!pqs.empty()){
            auto s = pqs.top();
            pqs.pop();
            /// 2-1 是否为结果
            if(s.vertex == end) return s.prob;
            /// 2-2 判断是否入栈
            for(auto &e : graph[s.vertex]){
                if(s.prob * e.second > record[e.first]){
                    record[e.first] = s.prob * e.second;
                    pqs.push({e.first, record[e.first]});
                }
            }
        }
        return 0;
    }
};
}