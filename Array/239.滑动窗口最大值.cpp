//
// Created by l1nkkk on 2021/8/10.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;

namespace leetcode239{
class MonotonicQueue{
public:
    // 从队尾插入，如果小于它的都弹出
    void push(int n){
        while(!data.empty()&&data.back() < n){
            data.pop_back();
        }
        data.push_back(n);
    }
    // 如果对头是n，则弹出
    void pop(int n){
        if(data.front() == n)
            data.pop_front();
    }

    // 对头是最大的
    int getMax(){
        return data.front();
    }
private:
    list<int> data;
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int lo,hi;
        vector<int> res;
        MonotonicQueue mq;
        // [lo, hi）
        lo = 0;
        hi = 0;
        while(hi < nums.size()){
            if(hi-lo != k){
                mq.push(nums[hi]);
                ++hi;
            }else{
                res.push_back(mq.getMax());
                mq.push(nums[hi]);
                ++hi;
                mq.pop(nums[lo]);
                ++lo;
            }
        }
        res.push_back(mq.getMax());
        return res;
    }
};

void test(){
    Solution s;
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    auto res = s.maxSlidingWindow(input,3);
    cout << "Tes" ;
}
}