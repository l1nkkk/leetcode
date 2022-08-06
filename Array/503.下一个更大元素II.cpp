//
// Created by l1nkkk on 2021/7/27.
//
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
namespace leetcode503{
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> newNums = nums;
        vector<int> res(newNums.size(),-1);

        for( auto it: nums){
            newNums.push_back(it);
        }

        /** 单调栈*/
        stack<int> st;
        for( int i = newNums.size()-1; i >= 0; --i){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            res[i] = st.empty()? -1 : st.top();
            st.push(newNums[i]);
        }
        return vector<int>(res.begin(), res.begin()+ nums.size());
    }
};
void test(){
    Solution s;
    vector<int> v{1,2,1};
    auto res = s.nextGreaterElements(v);
    for(auto i : res){
        cout << i <<" ";
    }
}
}