//
// Created by l1nkkk on 2021/8/6.
//
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <map>
using namespace std;
namespace leetcode773{
    class Solution {
    public:
        map<int, vector<int>> neg = {
                {0,{1,3}},
                {1,{0,2,4}},
                {2,{1,5}},
                {3,{0,4}},
                {4,{1,3,5}},
                {5,{2,4}},
        };
        int slidingPuzzle(vector<vector<int>>& board) {
            queue<string> q;
            set<string> record;
            string boardStr;
            string target = "123450";
            int heigh = 1;
            for (auto &x : board) {
                for (auto &y : x) {
                    boardStr = boardStr + char(y + '0');
                }
            }
            if (boardStr == target)
                return 0;

            q.push(boardStr);
            while (!q.empty()) {
                int num = q.size();
                for (int i = 0; i < num; ++i) {

                    auto s = q.front();
                    q.pop();
                    auto pos = s.find('0');
                    // 交换位置
                    for (auto j : neg[pos]) {
                        string ts = s;
                        swap(ts[j], ts[pos]);
                        if (ts == target)
                            return heigh;
                        if (record.find(ts) == record.end()) {
                            record.insert(ts);
                            q.push(ts);
                        }
                    }
                }

                ++heigh;
            }
            return -1;

        }
    };
}