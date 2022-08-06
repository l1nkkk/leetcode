//
// Created by l1nkkk on 2021/9/12.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace leetcode93{
class Solution {
public:
    vector<string> res;
    vector<string> cur;
    vector<string> restoreIpAddresses(string s) {
        dfs(s,0);
        return res;
    }
    void dfs(string s, int level){
        if(s == "") return;
        // 取
        if(level == 3){
            if(s.size() > 3)
                return;
            auto t = stoi(s);
            if(t > 255){
                return;
            }else if(s[0] == '0' && s.size() != 1){
                return;
            }else{
                string str;
                int n = 0;
                for(auto t : cur){
                    str += t + '.';
                }
                str += s;
                res.push_back(str);
            }
        }else{
            if(s[0] != '0'){
                for(int i = 1; i <= 3 && i < s.size(); ++i){
                    auto t = stoi(s.substr(0,i));
                    if(t > 255){
                        break;
                    }
                    cur.push_back(s.substr(0,i));
                    dfs(s.substr(i), level+1);
                    cur.pop_back();
                }
            }else{
                cur.push_back(s.substr(0,1));
                dfs(s.substr(1), level+1);
                cur.pop_back();
            }
        }
    }
};
void test(){
    Solution s;
    auto res = s.restoreIpAddresses("0279245587303");
    for(auto r : res){
        cout << r << endl;
    }
}
}