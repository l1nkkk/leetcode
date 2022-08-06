//
// Created by l1nkkk on 3/29/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

namespace leetcode443{
class Solution1 {
public:
    int compress(vector<char>& chars) {
        int x = 0;  // 遍历
        int y = 0; // 重新构造
        while(x < chars.size()){

            int subx = x+1;
            char cur = chars[x];
            // 看连续了多久
            while(subx < chars.size() && chars[subx] == cur){
                ++subx;
            }

            // 退出判断
            if(subx == x+1){
                chars[y++] = cur;
            }else{
                chars[y++] = cur;
                if(subx > chars.size()){
                    chars[y++] = cur;
                }
                stringstream ss;
                string temp;
                ss << subx - x;
                ss >> temp;
                for(auto &a : temp) {
                    chars[y++] = a;
                }
            }
            // 更新x
            x = subx;
        }
        chars.resize(y);
        return y;

    }
};

// 空间复杂度o(1)
class Solution {
public:
    string toString(int a){
        string res;
        while(a){
            res.push_back((a%10)+'0');
            a/=10;
        }
        // 反转
        reverse(res.begin(),res.end());
        return res;
    }

    void deal(vector<char>& chars, int& slow ,int& pos, int& fast){
        auto res = toString(fast- pos);
        chars[slow++] = chars[pos];
        // res == 1 不需要写入数字
        if(res != "1")
            for(auto r : res){
                chars[slow++] = r;
            }
        pos = fast++;
    }

    int compress(vector<char>& chars) {
        // idea：双指针思想
        int slow, pos, fast;
        slow = 0;
        pos = 0;
        fast = 0;
        while(fast < chars.size()){
            if(chars[fast] == chars[pos]){
                ++fast;
            }else{
                // 处理编码
                deal(chars, slow, pos, fast);
            }
        }
        deal(chars, slow, pos, fast);

        return slow;

    }
};

void test(){
    Solution s;
//    vector<char> v = {'a','a','b','b','c','c','c'};
//    vector<char> v = {'a'};
    vector<char> v = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    s.compress(v);

    for_each(v.begin(),v.end(),[](char &it){cout << it << " ";});
}
}