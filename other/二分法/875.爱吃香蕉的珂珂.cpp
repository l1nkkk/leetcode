//
// Created by l1nkkk on 2022/3/23.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode875{
class Solution {
public:
    // 1. 定义f: 在猴子吃香蕉的速度为k的前提下，保卫至少需要离开H小时，k 越大 f(piles,k) 越小.
    int f(vector<int>& piles, int k){
        int res = 0;
        for(auto a : piles){
            res = res + (a+k-1) / k;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // 2. 定义边界
        int lo = 1;
        int hi = 0;
        for(auto p : piles){
            hi = hi < p ? p : hi;
        }
        // 3. 考虑二分写法; [lo, hi]，break时 lo+1 == hi
        while(lo <= hi){
            int mid = (lo+hi)/2;
            int hm = f(piles, mid);
            if(hm == h){
                // 需要求得f(piles, mid) == h，最小的k，所以靠左
                hi = mid;
            }else if(hm < h){
                // 如何让hm变大
                hi = mid;
            }else{
                // 如何让hm变小
                lo = mid+1;
            }
        }
        return hi;
    }
};

void test(){

}

}