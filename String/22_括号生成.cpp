//
// Created by l1nkkk on 4/6/21.
//

#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

namespace  leetcode22 {
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1){
            return {"()"};
        }
        auto pre = generateParenthesis(n-1);
        vector<string> res;
        res.push_back("()"+pre[0]);
        for(auto p : pre){
            int start = 0;
            while(p.find('(',start) != string::npos){
                auto temp = p;
                auto put = temp.insert(temp.find('(', start)+1,"()");
                res.push_back(put);
                start = p.find('(',start)+1;
            }
        }
        return res;

    }
};
void test(){
    Solution s;
    auto v = s.generateParenthesis(3);
    for(auto &it : v){
        cout << it << " ";
    }
}

}