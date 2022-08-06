//
// Created by l1nkkk on 2021/10/3.
//

#include <iostream>
using namespace std;
namespace leetcode470{

class Solution {
public:
    int rand7();
    int rand10() {
        while(true){
            int rtn = ((rand7()-1)*7) + rand7();
            if(rtn <= 40) return rtn%10+1;
            rtn = ((rtn-1)*7) + rand7();
            if(rtn <= 60) return rtn%10+1;
            rtn = ((rtn-1)*7) + rand7();
            if(rtn <= 20) return rtn%10+1;
        }
    }
};
}