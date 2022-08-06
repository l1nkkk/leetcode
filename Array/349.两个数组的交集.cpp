//
// Created by l1nkkk on 2021/10/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

namespace leetcode349{
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int x,y;
        int preVal;
        vector<int> res;
        x = 0;
        y = 0;
        preVal = min(nums1[0], nums2[0]) - 1;
        while(x < nums1.size() && y < nums2.size()){
            if(nums1[x] == nums2[y] && nums1[x] != preVal){
                res.push_back(nums1[x]);
                preVal = nums1[x];
                while(x < nums1.size() && nums1[x] == preVal)
                    ++x;
                while(y < nums2.size() && nums2[y] == preVal)
                    ++y;
            }else if(nums1[x] < nums2[y]){
                ++x;
            }else if (nums1[x] > nums2[y]){
                ++y;
            }
        }
        return res;
    }
};

void test(){
    vector<int> input1{1,2,2,1};
    vector<int> input2{2,2};
    Solution s;
    auto res = s.intersection(input1, input2);
    for(auto &r : res){
        cout << r;
    }
}
}

