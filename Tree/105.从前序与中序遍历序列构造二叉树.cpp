//
// Created by l1nkkk on 2021/7/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace leetcode105{
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
    // 定义，构造树，并且返回根
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                   vector<int>& inorder, int inStart, int inEnd){
        // base case
        if(preStart > preEnd) return nullptr;

        TreeNode* rt = new TreeNode(preorder[preStart]); // root
        // 找到中序根的位置
        int in_rt = inStart;
        while(in_rt <= inEnd){
            if(inorder[in_rt] == preorder[preStart])
                break;
            ++in_rt;
        }

        int leftSize = in_rt - inStart;

        rt->left = build(preorder,preStart+1, preStart+ leftSize,
              inorder, inStart, in_rt - 1);
        rt->right = build(preorder, preStart+ leftSize+1, preEnd,
              inorder, in_rt+1, inEnd);
        return rt;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1,
                     inorder, 0, inorder.size()-1);
    }
};
void test(){
    Solution s;
    vector<int> pre{3,9,20,15,7}, in{9,3,15,20,7};
    auto res = s.buildTree(pre,in);

}
}