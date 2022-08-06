//
// Created by l1nkkk on 2021/7/31.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
using namespace std;

namespace leetcode710{
class Solution {
public:
    unordered_map<int,int>record;
    int sp = 0;

    Solution(int n, vector<int>& blacklist) {
        sp = n - blacklist.size();
        int last = n -1;
        for(auto b : blacklist){
            record[b] = 666;
        }

        for(auto b : blacklist){

            if(b >= sp){
                continue;
            }
            while(record.find(last) != record.end()){
                --last;
            }
            record[b] = last;
            last--;
        }

    }

    int pick() {
        int r = rand() & sp;
        if(record.find(r) == record.end()){
            return sp;
        }
        return record[r];
    }
};

}