//
// Created by l1nkkk on 2021/8/19.
//

#include <vector>
#include <iostream>
using namespace std;

namespace leetcode88{
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int pos = m+n-1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[pos--] = nums1[i--];
            }else{
                nums1[pos--] = nums2[j--];
            }
        }

        while(j >= 0){
            nums1[pos--] = nums2[j--];
        }
        while(i >= 0){
            nums1[pos--] = nums1[i--];
        }

    }
};


void test(){
    Solution s;
    vector<int> n1{1,2,3,0,0,0},n2{2,5,6};
    s.merge(n1,3,n2,3);
    cout <<"te" ;
}
}