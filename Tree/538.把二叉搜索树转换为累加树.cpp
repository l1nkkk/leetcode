//
// Created by l1nkkk on 2021/7/20.
//

namespace leetcode538{
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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        convertBST(root->right);

        /** 中序遍历*/
        sum += root->val;
        root->val = sum;

        convertBST(root->left);
        return root;
    }
};
}