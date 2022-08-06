//
// Created by l1nkkk on 2021/11/3.
//
#include <iostream>
#include <vector>

using namespace std;
namespace offer21{
class Solution {
public:
    bool check(int nums){
        return nums&1;
    }
    vector<int> exchange(vector<int>& nums) {
        int start, end;
        start = 0;
        end = nums.size() - 1;
        while(start < end){

            while(start <= end && check(nums[start])){
                ++start;
            }
            if(start > end)
                break;

            while(start <= end && !check(nums[end])){
                --end;
            }
            if(start > end)
                break;
            swap(nums[start], nums[end]);
        }
        return nums;
    }
};

void test(){
    Solution s;
    vector<int> input{1,3,5};
    auto res = s.exchange(input);
    for( auto r : res)
        cout << r << " ";
}
}
