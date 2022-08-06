//
// Created by l1nkkk on 3/29/21.
//
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


namespace leetcode556{
class Solution {
public:
    int nextGreaterElement(int n) {
        int64_t res;
        stringstream ss;
        ss << n;
        string strn = ss.str();

        // 从右到左找到第一个递增的，取到位置
        int pos;
        for(pos = strn.length()-1; pos > 0; --pos){
            if(strn[pos-1] < strn[pos]){
                break;
            }
        }
        if(pos == 0){
            return -1;
        }
        pos -= 1;
        // 从取到的位置从右到左找，找第一个比pos大的，然后交换
        for(int i =  strn.length()-1; i > pos; --i){
            if(strn[i] > strn[pos]){
                strn[i] ^= strn[pos];
                strn[pos] ^= strn[i];
                strn[i] ^= strn[pos];
                break;
            }
        }
        // 对pos之后的哪些字符排序
        sort(strn.begin()+pos+1,strn.end());

        ss.clear();
        ss.str("");
        ss << strn;
        ss >> res;
        if(res > (pow((double)2,31) - 1))
            return -1;
        return res;
    }
};

void test(){
    Solution s;
    cout << s.nextGreaterElement(2147483476);
}
}