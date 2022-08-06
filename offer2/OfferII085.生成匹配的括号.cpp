//
// Created by l1nkkk on 2022/8/3.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer2_85{
class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        dfs("",n,n);
        return res;
    }
    void dfs(string status,int left, int right){
        if(left == 0 && right == 0){
            res.push_back(status);
            return;
        }
        if(left > 0 && left <= right){
            dfs(status+"(",left-1, right);
        }
        if(right > 0 && right > left){
            dfs(status+")",left,right-1);
        }
    }
};
}