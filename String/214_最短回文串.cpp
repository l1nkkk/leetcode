//
// Created by l1nkkk on 3/30/21.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


namespace leetcode214{
class Solution {
public:
    bool check(const string &s){
        int i = 0;
        int j = s.length()-1;

        while (i < j){
            if(s[i] != s[j])
                break;
            ++i;
            --j;
        }
        return i >= j;
    }
    string shortestPalindrome(string s) {
        if(s == "") return "";
        uint64_t base = 131, mod = 1000000007;
        uint64_t iter = 1;
        uint64_t res1 = 0, res2 = 0;
        int i = 0;
        int pos = 0;
        for(i = 0; i < s.length(); ++i){
            res1 = ((res1 * base)%mod + s[i]) % mod;
            res2 = (res2 + ((iter * s[i])%mod))%mod;
            iter = (iter * base) % mod;
//            if(res1 == res2 && check(s.substr(0,i+1))){
            if(res1 == res2){
                pos = i;
            }
        }
        string add = (pos == s.length()-1 ? "" : s.substr(pos + 1,s.length()-pos-1));
        reverse(add.begin(), add.end());
        return add + s;

    }
};

void test(){
    Solution s;
    cout << s.shortestPalindrome("aacecaaa");

}
}