//
// Created by l1nkkk on 2022/4/13.
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;
namespace leetcode56_2{
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> record;
        for(auto a: nums){
            ++record[a];
        }
        for(auto a : record){
            if(a.second == 1)
                return a.first;
        }
    }
};
}