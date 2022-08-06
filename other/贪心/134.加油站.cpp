//
// Created by l1nkkk on 2022/3/20.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode134{
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minPoint=-1;
        int minVal=0;
        int tank = 0;
        for(int i = 0; i <gas.size(); ++i){
            tank += gas[i]-cost[i];
            if(tank < minVal){
                minVal = tank;
                minPoint = i;
            }
        }
        if(tank < 0) return -1;
        else return minPoint+1;

    }
};

void test(){
    vector<int> gas1{1,2,3,4,5}, cost1{3,4,5,1,2};
    Solution s;
    cout << s.canCompleteCircuit(gas1, cost1);
}

}