//
// Created by l1nkkk on 2021/11/3.
//
#include <iostream>
#include <vector>
using namespace std;

namespace offer10_2{
class Solution {
public:
    int numWays(int n) {
        int cur  = 0;
        int record[2]{0,1};

        while(cur < n){
            record[cur&1] = (record[0] + record[1]) % 1000000007;
        }
        return record[n&1];
    }
};
}
