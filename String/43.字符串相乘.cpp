//
// Created by l1nkkk on 2021/8/11.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace leetcode43{
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        else if(num1 == "1")
            return num2;
        else if(num2 == "1")
            return num1;

        // 手算乘法处理
        vector<int> res(num1.size()+num2.size(),0);
        for(int i = num1.size()-1; i >= 0; --i){
            for(int j = num2.size()-1; j >= 0; --j){
                int p1 = i + j +1;
                int p2 = p1 - 1;
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                int mul = n1 * n2 + res[p1];
                res[p1] = mul % 10;
                res[p2] += mul / 10;

            }
        }
        int pos = 0;
        while(res[pos] == 0){
            ++pos;
        }
        string rtn = "";
        while(pos < res.size()){
            rtn += std::to_string(res[pos++]);
        }
        return rtn;
    }
};
void test(){
    Solution s;
    cout << s.multiply("123","45");
}
}