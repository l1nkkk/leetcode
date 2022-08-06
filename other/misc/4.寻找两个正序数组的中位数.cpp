//
// Created by l1nkkk on 2021/10/2.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

namespace leetcode4{
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 要找到第k大的数，从1开始
        int k = (nums1.size() + nums2.size()+ 1)/2 ; // (2 +3) /2
        if((nums1.size() + nums2.size()) & 1)
            return getKth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), k);
        else
            return (getKth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), k)+
            getKth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), k+1))/2.0;
    }

private:
    // [l1,r1), [l2,r2)
    int getKth(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2, int k){
        // 只剩下一个数组有数的情况
        if(l1 == r1)
            return nums2[l2+k-1];
        if(l2 == r2)
            return nums1[l1+k-1];
        if(k == 1){
            return min(nums1[l1], nums2[l2]);
        }

        // 两边各取的数量为t
        int t = k/2;
        int pos1,pos2;
        // 判断边界
        if(l1+t > r1) pos1 = r1-1;
        else pos1 = l1+t-1;
        if(l2+t > r2) pos2 = r2-1;
        else pos2 = l2+t-1;
        if(nums1[pos1] < nums2[pos2]){// pos1 out
            return getKth(nums1, nums2, pos1+1, r1, l2, r2, k-pos1+l1-1);
        }else{
            return getKth(nums1, nums2, l1, r1, pos2+1, r2, k-pos2+l2-1);
        }

    }
};


void test(){
    Solution s;
    vector<int> input1{1,3};
    vector<int> input2{2};
    cout << s.findMedianSortedArrays(input1, input2);
}

}