//
// Created by l1nkkk on 2021/10/9.
//

#include <iostream>
#include <vector>
using namespace std;



namespace leetcode162{
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        auto get = [&nums](int i)-> pair<int, int>{
            if(i == -1 || i == nums.size()){
                return {0,0};
            }else{
                return {1, nums[i]};
            }
        };

        // 二分法
        int left = 0;
        int right = nums.size()-1;
        // [left,right]
        while(left < right){
            int mid = left + (right - left)/2;
            // 1.刚好是顶峰
            if(get(mid-1) < get(mid) && get(mid) > get(mid+1)){
                return mid;
            }else if(get(mid) < get(mid+1)){
                // 2. 上坡
                left = mid +1;
            }else {
                right = mid -1;
            }
        }
        return left;
    }
};
}