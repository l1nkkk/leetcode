//
// Created by l1nkkk on 2021/7/13.
//

#include <iostream>
using namespace std;

namespace leetcode114{
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
    // 定义：将以root为根的树拉平
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        // 1.将左右子树拉平
        flatten(root->left);
        flatten(root->right);

        /**** 后序遍历位置 ****/
        // 2.拉平后，将右边加到左边的尾部
        if(root->left != nullptr){
            TreeNode* lend = root->left;
            while(lend->right != nullptr){
                lend = lend->right;
            }
            lend->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        return;
    }
};
TreeNode* init(){
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(5);

    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(4);
//    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(6);
}
void test(){
    auto rt = init();
    Solution s;
    s.flatten(rt);
}
}