//
// Created by l1nkkk on 2021/7/24.
//
#include <vector>
using namespace std;
namespace leetcode167{
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left, right;
        left = 0;
        right = numbers.size()-1;
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                return {left+1,right+1};
            } else if(numbers[left] + numbers[right] < target) {
                ++left;
            } else if (numbers[left] + numbers[right] > target){
                --right;
            }
        }
        return {left+1,right+1};
    }
};
}