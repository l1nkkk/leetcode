//
// Created by l1nkkk on 2021/7/13.
//

#include <iostream>
#include <string>
using namespace std;

namespace leetcode226{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* init(){
    TreeNode* head = new TreeNode(4);
    head->left = new TreeNode(2);
    head->right = new TreeNode(7);

    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(3);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(9);
}
class Solution {
public:
    // 定义：返回翻转后的树的根节点
    TreeNode* invertTree(TreeNode* root) {
        // base case
        if(root == nullptr) return nullptr;
        auto l = invertTree(root->left);
        auto r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};
}