//
// Created by l1nkkk on 2021/7/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
namespace leetcode654{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
    // 递归定义：传入数组和[lo，hi)，生成符合题目要求的树，返回root
    TreeNode* build(vector<int>& nums, int lo, int hi){
        if(lo >= hi) return nullptr;
        // 找到最大
        int maxI = lo;
        for(int i = lo; i <hi; ++i){
            maxI = nums[maxI] < nums[i] ? i : maxI;
        }
        TreeNode* rtn = new TreeNode(nums[maxI]);
        rtn->left = build(nums, lo, maxI);
        rtn->right = build(nums, maxI+1, hi);
        return rtn;
    }
};

void test(){
    Solution s;
    vector<int> v{3,2,1,6,0,5};
    s.constructMaximumBinaryTree(v);
}
}