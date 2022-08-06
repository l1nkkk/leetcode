//
// Created by l1nkkk on 2021/8/4.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

namespace leetcode752{
class Solution {
public:
    set<string> record;
    set<string> deads;
    map<char,vector<char>> trans{
            {'0',{'9','1'}},
            {'1',{'0','2'}},
            {'2',{'1','3'}},
            {'3',{'2','4'}},
            {'4',{'3','5'}},
            {'5',{'4','6'}},
            {'6',{'5','7'}},
            {'7',{'6','8'}},
            {'8',{'7','9'}},
            {'9',{'8','0'}},
    };
    int openLock(vector<string>& deadends, string target) {
        if(find(deadends.begin(), deadends.end(), "0000") != deadends.end()){
            return -1;
        }
        if(target == "0000" ){
            return 0;
        }
        for(auto d : deadends){
            deads.insert(d);
        }


        queue<string> q;
        int depth = 1;
        q.push("0000");
        record.insert("0000");
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; ++i){
                auto s = q.front();
                q.pop();
                for(int j = 0; j < 4; ++j){
                    string temp = s;

                    char c = temp[j];
                    temp[j] = trans[c][0];
                    if(temp == target)
                        return depth;
                    if(deads.find(temp) == deads.end() && record.find(temp) == record.end()){
                        q.push(temp);
                        record.insert(temp);
                    }

                    temp[j] = trans[c][1];
                    if(temp == target)
                        return depth;
                    if(deads.find(temp) == deads.end() && record.find(temp) == record.end()){
                        q.push(temp);
                        record.insert(temp);
                    }
                }

            }

            depth++;
        }
        return -1;
    }
};

void test(){
    Solution s;
//    vector<string> inp = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    vector<string> inp = {"0201","0101","0102","1212","2002"};
    cout << s.openLock(inp, "0202");
}
}