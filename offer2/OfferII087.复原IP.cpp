//
// Created by l1nkkk on 2022/8/3.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace offer2_87{
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        dfs(s,"",0,1);
        return res;
    }
    void dfs(string& s, string now, long long  start, long long  level){
        if(level == 4){
            auto t = s.substr(start);
            if((t[0] != '0' || t.size() == 1) && t.size() <= 3 && atoi(t.c_str()) <= 255)
                res.push_back(now+"."+t);
            return;
        }
        for(int i = 0; i < 3; ++i){
            if(start+i+1 >= s.size())
                return;
            auto t = s.substr(start, i+1);
            if((t[0] != '0' || t.size() == 1) && atoi(t.c_str()) <= 255){
                if(now != "")
                    dfs(s, now+"."+t, start+i+1,level+1);
                else
                    dfs(s, t, start+i+1,level+1);
            }else{
                return;
            }
        }
    }
};

void test(){
    Solution s;
    auto res = s.restoreIpAddresses("1111");
    for(auto r: res){
        cout << r << " ";
    }
}
}