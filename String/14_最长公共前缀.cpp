//
// Created by l1nkkk on 4/3/21.
//
#include <vector>
#include <iostream>
#include <string>
using namespace std;

namespace leetcode14{



class Solution {
public:
    const string check(string s1, string s2){
        int i;
        for(i = 0; i < s1.length(); ++i){
            if(s1[i] != s2[i])
                break;
        }
        return i == s1.length()? s1:s1.substr(0, i);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string cmp = strs[0];
        for (auto &it : strs){
            cmp = check(cmp,it);
            if(cmp == "") break;
        }
        return cmp;
    }
};
};