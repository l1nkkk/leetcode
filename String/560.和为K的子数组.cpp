//
// Created by l1nkkk on 2022/3/10.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;



namespace leetcode560{
class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
    // preSum ==> times
    unordered_map<int, int> recordPreSum;
    recordPreSum[0] = 1;
    int preSum = 0;
    int res = 0;
    for(auto n : nums){
        preSum += n;
        if(recordPreSum.count(preSum-k))
            res += recordPreSum[preSum-k];

        ++recordPreSum[preSum];
    }
    return res;
}
};

void test(){
    Solution s;
    {
        vector<int> input{1,2,3};
        cout << s.subarraySum(input,3);
    }
    {
        vector<int> input{1};
        cout << s.subarraySum(input,0);
    }

}
}