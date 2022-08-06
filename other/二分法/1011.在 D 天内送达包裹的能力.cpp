//
// Created by l1nkkk on 2022/3/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace leetcode1011{
class Solution {
public:
    // 1. 定义：给定运载能力 p, 返回至少需要的运载天数 f(weights, p); p 越大 f 越小
    int f(vector<int> weights, int p){
        int res = 0;
        int t = 0;
        for( auto w : weights){
            if(t < w){
                ++res;
                t = p;
                t -= w;
            }else
                t -= w;
        }
        return res;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        sort(weights.begin(), weights.end());
        // 2. 确定边界
        int lo = 0,hi = 0;
        // lo 取 weights 中最大的， hi 取sum(weights)
        for( auto w : weights){
            hi += w;
            lo = lo < w ? w : lo;
        }
        // 3. 判断二分写法； [lo, hi] 表示可能的结果范围，应该取尽可能小的结果
        while(lo < hi){
            int mid = (lo + hi) /2;
            int dm = f(weights, mid);
            if(dm == days){
                hi = mid;
            }else if(dm < days){
                hi = mid;
            }else if(dm > days){
                lo = mid+1;
            }
        }
        return hi;
    }
};

void test(){
    vector<int> input{3,2,2,4,1,4};
    Solution s;
    cout << s.shipWithinDays(input, 3);
}

}