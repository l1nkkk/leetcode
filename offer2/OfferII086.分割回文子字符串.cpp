//
// Created by l1nkkk on 2022/8/3.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace offer2_86{
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> now;
        dfs(s,now);
        return res;
    }
    void dfs(string status, vector<string>& now){
        if(status == ""){
            res.push_back(now);
            return;
        }
        for(int i = 0; i < status.size(); ++i){
            auto t = status.substr(0, i+1);
            if(check(t)){
                now.push_back(t);
                dfs(status.substr(i+1),now);
                now.pop_back();
            }
        }
    }
    bool check(string str){
        static unordered_map<string,bool> record;
        if(record.count(str) > 0)
            return record[str];
        int lo = 0;
        int hi = str.size()-1;
        while(lo < hi){
            if(str[lo] != str[hi]){
                record[str] = false;
                return false;
            }
            ++lo;
            --hi;
        }
        record[str] = true;
        return true;
    }

};

void test(){
    Solution s;
    s.partition("google");
}
}