//
// Created by l1nkkk on 2021/11/12.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode402{
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0"; // 特殊情况：全部删除
        string res;
        int i;
        for(i = 0; i < num.size(); ++i){
            // 不需要删了
            if(k == 0){
                res += num.substr(i);
                break;
            }
            if(num[i] == '0'){
                res += num[i];
            }else if(num[i] > num[i+1]){// 递减
                --k;
                continue;
            }else
                res += num[i];
        }

        // 补丁，消除前缀0
        int pos = 0;
        while(pos < res.size()-1&&res[pos] == '0'){ // 留一个，00000不全清
            ++pos;
        }

        return res.substr(pos);
    }
};

void test(){
    Solution s;
//    cout << s.removeKdigits("10200",1) << endl;
//    cout << s.removeKdigits("1432219",3) << endl;
//    cout << s.removeKdigits("10",1) << endl;
    cout << s.removeKdigits("112",1) << endl;
}
}