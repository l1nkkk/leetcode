//
// Created by l1nkkk on 2021/7/21.
//

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        return count(1,n);
    }

    int count(int lo, int hi){
        // 备忘录
        static vector<vector<int> > note(20, vector<int>(20, -1));
        // base case
        if(lo > hi){ return  1;}
        if(note[lo][hi] != -1) return note[lo][hi];
        int res = 0;
        for(int i = lo; i <= hi; ++i){
            auto left = count(lo,i-1);
            auto right = count(i+1, hi);
            res += left * right;
        }
        note[lo][hi] = res;
        return res;

    }
};