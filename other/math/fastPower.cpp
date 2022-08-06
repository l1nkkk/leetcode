//
// Created by l1nkkk on 2021/8/7.
//
#include <iostream>
using namespace std;
namespace fastpower{
int fastPower(int a, int b, int mod =1337){
    int base = a%mod;
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * base)%mod;
        }
        base = (base * base)%mod;
        b >>= 1;
    }
    return res;
}

void test(){
    cout << fastPower(2, 10);
}

}