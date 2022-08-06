//
// Created by l1nkkk on 2022/4/3.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace leetcode743{
class Solution {
public:
    vector<int> record; // 记录从 n 到 i 的最小的距离
    vector<vector<pair<int,int>>> graph; // to weight
    struct State{
        int vetex;
        int curPath;
        State(int v, int c) : vetex(v), curPath(c){}
    };
    struct cmp{
        bool operator()(State& s1, State& s2){
            return s1.curPath > s2.curPath;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /// 1. init
        record = vector<int>(n+1, INT32_MAX); // 由于从1开始
        record[k] = 0;// 起点处设置为0

        /// 1.1 生成图
        graph = vector<vector<pair<int,int>>>(n+1);
        for(auto &t : times){
            graph[t[0]].push_back({t[1],t[2]});
        }

        // 2. dijkstra
        priority_queue<State,vector<State>, cmp> pqs;
        pqs.push(State(k,0));   // add for start, 从 k 出发
        while(!pqs.empty()){
            auto v = pqs.top();
            pqs.pop();

            /// 2-1 遍历当前节点v的所有边
            for(auto &e : graph[v.vetex]){
                // 判断curPath，是否可以加入队列
                if(v.curPath + e.second < record[e.first]){
                    // 入队列
                    record[e.first] = v.curPath + e.second;
                    pqs.push(State{e.first, record[e.first]});
                }
            }

        }

        /// 3 获取结果
        // 算出最大的record
        int res = 0;
        for(int i = 1; i < record.size(); ++i){

            res = record[i] > res ? record[i] : res;
        }
        return res != INT32_MAX ? res : -1;
    }

};

//struct  cmp{
//    bool operator()(int a,int b){return a <b;}
//};


void test(){
    vector<vector<int>> input{{2,1,1},{2,3,1},{3,4,1}};
    Solution s;
    auto res = s.networkDelayTime(input, 4,2);
    cout << res;

}

}