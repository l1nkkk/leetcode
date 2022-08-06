//
// Created by l1nkkk on 2022/3/15.
//

#include <iostream>
#include <vector>
using namespace std;


namespace leetcode327{
class Solution {
public:
    int lower_;
    int upper_;
    int res = 0;
    vector<int> temp;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        temp.resize(nums.size()+1);
        lower_ = lower;
        upper_ = upper;
        /// 前缀和数组，总大小是 nums.size()+1
        vector<int> pre(nums.size()+1);
        for(int i = 0; i < nums.size(); ++i){
            pre[i+1] = pre[i] + nums[i];
        }

        sort(pre, 0 , pre.size());
        return res;
    }

    void sort(vector<int>& pre, int lo, int hi){
        if(lo+1 >= hi) return;
        int mid = (lo + hi) /2;
        sort(pre, lo, mid);
        sort(pre, mid, hi);
        mergeAndDeal(pre, lo, mid, mid , hi);
    }

    void mergeAndDeal(vector<int>& pre, int lo1, int hi1, int lo2, int hi2){
        int start = lo2;
        int end = lo2;

        /// 注意分析[0,0]这种情况是怎么一回事，得益于前缀和多出的那一个元素
        /// 额外私料，求取结果
        for(int i = lo1; i < hi1; ++i){
            /// 注意这里是 < 号
            while(start < hi2 && pre[start]-pre[i] < lower_)
                ++start;
            /// 注意这里是 <= 号，要让空间尽可能大
            while(end < hi2 && pre[end] - pre[i] <= upper_)
                ++end;
//            cout << i << " " <<  start << " " << end << endl;
            res += end-start;
        }


        /// 归并套路
        start = lo1;
        int pos = lo1;
        while(lo1 < hi1 || lo2 < hi2){
            if(lo1 >= hi1){
                temp[pos++] = pre[lo2++];
            }else if(lo2 >= hi2){
                temp[pos++] = pre[lo1++];
            }else if(pre[lo1] < pre[lo2]){
                temp[pos++] = pre[lo1++];
            }else{
                temp[pos++] = pre[lo2++];
            }
        }
        pos = start;
        while(pos != hi2){
            pre[pos] = temp[pos];
            pos++;
        }


    }
};

void test(){
    Solution s;
    vector<int> input{-2,5,-1};


    cout << s.countRangeSum(input,-2,2);
    cout << endl;
    for(auto t : s.temp){
        cout << t << " ";
    }
    cout << endl;
}

}