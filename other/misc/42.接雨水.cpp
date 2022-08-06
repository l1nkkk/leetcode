//
// Created by l1nkkk on 2021/9/11.
//
#include <iostream>
#include <vector>
using namespace std;

namespace leetcode42{
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        int lmax = height[0];
        int rmax = height[height.size()-1];
        int left = 0;
        int right = height.size()-1;
        int res = 0;
        while(left <= right){
            lmax = max(height[left], lmax);
            rmax = max(height[right], rmax);

            if(lmax < rmax){
                res += lmax - height[left];
                ++left;
            }else{
                res += rmax - height[right];
                --right;
            }

        }
        return res;
    }
};
}