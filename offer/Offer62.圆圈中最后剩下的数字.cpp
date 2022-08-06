//
// Created by l1nkkk on 2021/11/10.
//

#include <iostream>
using namespace std;

namespace offer62{
class Solution {
public:
    int lastRemaining(int n, int m) {
        int i = 1;
        int res = 0;
        // 迭代 n-1次
        while( i < n ){
            res = (res + m)%(++i);
        }
        return res;
    }
};

void test(){
    Solution s;
    cout << s.lastRemaining(10,17);
}
}