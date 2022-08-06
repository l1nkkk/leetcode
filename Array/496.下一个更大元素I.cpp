//
// Created by l1nkkk on 2021/7/27.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;

namespace leetcode496{
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> valToRes;
        stack<int> st;
        // 每一个需要知道后面的情况，所以从后面遍历
        for(int i = nums2.size()-1; i >= 0; --i){
            // 被挡到了，已经没用了，弹开
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }
            valToRes[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); ++i){
            nums1[i] = valToRes[nums1[i]];
        }
        return nums1;

    }
};
}