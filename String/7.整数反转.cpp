//
// Created by l1nkkk on 2021/11/3.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

namespace leetcode7{
class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        int res = 0;
        if(x == INT32_MIN) return 0;
        if(x < 0){
            flag = true;
            x = -x;
        }
        while(x != 0){
            if(INT32_MAX/10 < res )
                return 0;
            else if(INT32_MAX/10 == res && INT32_MAX%10 < x%10)
                return 0;
            res = res * 10 + (x % 10);
            x /= 10;
        }
        return flag ? -res: res;
    }
};

void test(){
    Solution s;
    cout << s.reverse(1463847412);
}

}