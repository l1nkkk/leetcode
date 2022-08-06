//
// Created by l1nkkk on 2021/8/2.
//

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

namespace leetcode46{
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int pre,next;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(vector<int>(nums.begin(), nums.end()));


        while(true){
            next = nums.size()-1;
            pre = next-1;
            // 1.从右到左，找到递增的
            while(pre >= 0){
                if(nums[pre] < nums[next]){
                    break;
                }
                --pre;
                --next;
            }
            if(pre < 0)// 一直没找到的情况
                break;

            // 2.找到比该数大最小且最靠右边的一个。eg:0122的情况找最后一个2
            int i = nums.size()-1;
            while(i >= next){
                if(nums[i] > nums[pre])
                    break;
                --i;
            }
            if(i < next)
                break;

            swap(nums[pre], nums[i]);
            // 3.倒叙
            int start,end;
            start = next;
            end = nums.size()-1;
            while(start < end){
                swap(nums[start], nums[end]);
                ++start;
                --end;
            }

            res.push_back(vector<int>(nums.begin(),nums.end()));
        }
        return res;
    }
};
void test(){
    Solution s;
    vector<int> input{1,2,3};
    auto res = s.permute(input);
    cout << "test";
}
}