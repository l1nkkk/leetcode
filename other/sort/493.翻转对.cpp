//
// Created by l1nkkk on 2022/3/15.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode493{
class Solution {
public:
    vector<int> temp;
    int res=0;
    int reversePairs(vector<int>& nums) {
        temp.resize(nums.size());
        sort(nums, 0, nums.size());
        return res;
    }
    void sort(vector<int>&nums, int lo, int hi){
        if(lo+1 >= hi) return;
        int mid = (lo+hi)/2;
        sort(nums, lo, mid);
        sort(nums, mid, hi);

        mergeAndCheck(nums, lo, mid, mid, hi);
    }
    void show(vector<int>& nums, int lo, int hi){
        while(lo < hi){
            cout << nums[lo] << " ";
            ++lo;
        }
    }

    // 二分查找
    int binarySearch(vector<int>& nums, int start, int end, int64_t target){
        // [lo,hi)
        int lo = start;
        int hi = end;
        /// 1. [lo,hi)下，二分查找 lo 的赋值必须 mid+1，否则会死循环
        /// 2. 只要 lo 变动过， lo-1 一定有，target > nums[lo-1]*2
        /// 3. 只要hi变动过，保证 target <= nums[hi]*2，
        /// 4. 而最终 lo == hi，所以 lo 和 hi 所在位置，为第一个使得 target <= nums[hi]*2 的地方
        while(lo < hi){
            int mid = lo +(hi - lo)/2;
            if(target > nums[mid]*2){
                lo = mid+1;
            }else if(target < nums[mid]*2){
                hi = mid;
            }else if(nums[mid]*2 == target){
                hi = mid;
            }
        }
        return hi-start;
    }


    void mergeAndCheck(vector<int>& nums, int lo1, int hi1, int lo2, int hi2){
        int pos = lo1;
        int start = lo1;
        int end = hi2;

        /// 添加的新操作，通过二分查找，在右有序数组中找到符合条件的结果数，加私货
        // 计算结果
        for(int i = lo1; i < hi1; ++i){
            res += binarySearch(nums, lo2, hi2, nums[i]);
//            for(int j = lo2; j < hi2; ++j){
//                if(nums[i] > int64_t (nums[j])*2)
//                    ++res;
//                else
//                    break;
//            }
        }

        /// 归并排序框架
        while(lo1 < hi1 && lo2 < hi2){
            if(nums[lo1] < nums[lo2]){
                temp[pos++] = nums[lo1++];
            }else{
                temp[pos++] = nums[lo2++];
            }
        }

        while(lo1 < hi1){
            temp[pos++] = nums[lo1++];
        }
        while(lo2 < hi2){
            temp[pos++] = nums[lo2++];
        }

        for(pos = start; pos != end; ++pos){
            nums[pos] = temp[pos];
        }
    }
};

void test(){
    Solution s;
    vector<int> input{1,3,2,3,1};
    cout << s.reversePairs(input);
    for(auto a : input){
        cout << a << " ";
    }
}
}
