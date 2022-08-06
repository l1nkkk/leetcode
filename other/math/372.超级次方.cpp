//
// Created by l1nkkk on 2021/8/7.
//
#include <iostream>
#include <vector>
using namespace std;
namespace leetcode372{
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty())return 1;
        if(a == 1 || a == 0) return a;
        int res;
        res = fastPower(a,b.back(),1337);
        b.pop_back();
        auto aa = superPow(a, b);
        res = (res * fastPower(aa,10,1337)) % 1337;
        return res;
    }
    int fastPower(int a, int b, int mod){
        int res = 1;
        int base = a%mod;

        while(b){
            if(b & 1){
                res = (res * base)%mod;
            }
            base = (base * base) % mod;
            b >>=1;
        }
        return res;
    }
};

void test(){
    Solution s;
    vector<int> b{1,0};
    cout << s.superPow(2,b);
}
}