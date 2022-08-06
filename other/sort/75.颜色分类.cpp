//
// Created by l1nkkk on 2022/3/12.
//
#include <iostream>
#include <vector>
using namespace std;
namespace leetcode75{
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0,p2;
        p0 = 0; p2 = nums.size()-1;
        int i = 0;

        while(i <= p2){
            if(nums[i] == 0)
                swap(nums[p0++],nums[i++]);
            else if( nums[i] == 1)
                ++i;
            else{
                // 注意，这里的 i 不能++；避免以下情况
                //       p0    i     p2
                // 0 0 0 1 1 1 2 1 1 0
                swap(nums[p2--],nums[i]);
            }
        }
    }
};

void test(){
//    vector<int> input{1,2,0};
    vector<int> input{2,0,1};
//    vector<int> input{2,0,2,1,1,0};
    Solution s;
    s.sortColors(input);
    for(auto a : input)
        cout << a << " ";
}
}
