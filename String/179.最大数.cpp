//
// Created by l1nkkk on 2021/10/9.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


namespace leetcode179{
struct cmp{
    bool operator()(const string& s1, const string &s2){
        if (s1.size() == s2.size()){
            return s1 < s2;
        }else if(s1.size() < s2.size()){
            auto ts2 = s2.substr(0,s1.size());
            if(s1 == ts2){
                // 拿剩下的和s1继续比
                return operator()(s1 , s2.substr(s1.size(), s2.size()-s1.size()+1)) ;
            }else{
                return s1 < s2;
            }
        }else{
            auto ts1 = s1.substr(0, s2.size());
            if(ts1 == s2){
                // 拿剩下的和s2继续比
                return  operator()(s1.substr(s2.size(),s1.size()-s2.size()+1) , s2 );
            }else{
                return s1 < s2;
            }
        }
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numstr;
        string res;
        for_each(nums.begin(), nums.end(), [&numstr](const int n){ numstr.push_back(to_string(n));});
        sort(numstr.rbegin(), numstr.rend(), cmp());

        for_each(numstr.begin(), numstr.end(), [&res](const string &s){ res += s;});

        // 补丁：[0,0]情况
        int pos = 0;
        while(pos < res.size()-1 && res[pos] == '0'){
            ++pos;
        }
        return res.substr(pos);

    }
};

void test(){
    vector<int> input{0,0,0};
    Solution s;
    cout << s.largestNumber(input);
}
}