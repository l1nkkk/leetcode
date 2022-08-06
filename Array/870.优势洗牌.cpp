//
// Created by l1nkkk on 2021/7/24.
//
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
namespace leetcode870{
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());

        // 这种需要结果保持原来索引，但是又需要排序，往往通过一个辅助结构
        vector<pair<int, int>> nums2Ex;
        for(int i = 0; i < nums2.size(); ++i){
            nums2Ex.push_back(make_pair(i,nums2[i]));
        }
        sort(nums2Ex.begin(),nums2Ex.end(),[](pair<int,int> &p1, pair<int, int> &p2)->bool {
            return p1.second < p2.second;
        });
        int lo = 0;
        int hi = nums1.size()-1;
        int pos = nums2Ex.size()-1;
        vector<int> res(nums1.size(),0);

        while(lo <= hi){
            // 如果 n1 中 最大的都被 n2 的最大还大，用最弱的对战
            if(nums1[hi] <= nums2Ex[pos].second){
                res[nums2Ex[pos--].first] = nums1[lo++];
            }else{
                // 用最强的对战，无所谓浪费
                res[nums2Ex[pos--].first] = nums1[hi--];
            }
        }
        return res;
    }
};

void test(){
    vector<int> input1{2,7,11,15};
    vector<int> input2{1,10,4,11};
    Solution s;
    auto res = s.advantageCount(input1, input2);
    for(auto r : res){
        cout <<r << " ";
    }
}

}