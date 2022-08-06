//
// Created by l1nkkk on 2022/3/15.
//

#include <iostream>
#include <vector>

using namespace std;

namespace leetcode315{
class Solution {
public:
    /// 私料，辅助结构，将问题转化为对齐的归并
    /// 目的：需要记录值的原索引位置
    struct Pair{
        int index;
        int val;
    };
    vector<Pair> temp;

    /// 结果
    vector<int> count;

    vector<int> countSmaller(vector<int>& nums) {
        temp.resize(nums.size());
        count.resize(nums.size());
        vector<Pair> pairs;
        /// 将数组转化为辅助数组
        for(int i = 0; i < nums.size(); ++i){
            pairs.push_back(Pair{i, nums[i]});
        }
        sort(pairs, 0, nums.size());
        return count;
    }
    void sort(vector<Pair>& pairs, int lo, int hi){
        if( lo+1 >= hi ){
            return;
        }
        int mid = (lo + hi)/2;
        sort(pairs, lo, mid);
        sort(pairs, mid, hi);
        mergeAndDeal(pairs, lo, mid, mid, hi);
    }


    void mergeAndDeal(vector<Pair>& pairs, int lo1, int hi1, int lo2, int hi2){
        int pos = lo1;
        int start = lo1;
        int end = hi2;

        /// 归并套路，顺便处理所求
        while(lo1 < hi1 && lo2 < hi2){
            if(pairs[lo1].val > pairs[lo2].val){
                temp[pos++] = pairs[lo2++];
            }else{
                temp[pos++] = pairs[lo1];
                count[pairs[lo1].index]+= lo2-hi1;
                ++lo1;
            }
        }

        while(lo1 < hi1){
            temp[pos++] = pairs[lo1];

            count[pairs[lo1].index]+= lo2-hi1;
            ++lo1;
        }

        while(lo2 < hi2){
            temp[pos++] = pairs[lo2++];
        }

        pos = start;
        while(pos < hi2){
            pairs[pos] = temp[pos];
            ++pos;
        }

    }
};

void test(){
    Solution s;
    vector<int> input{5,2,6,1};
    auto res = s.countSmaller(input);
    for(auto t : s.temp){
        cout << t.val << " ";
    }
    cout << endl;
    for(auto a:res){
        cout << a << " ";
    }
}
}