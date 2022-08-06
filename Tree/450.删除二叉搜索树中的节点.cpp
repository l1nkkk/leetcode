//
// Created by l1nkkk on 2021/7/20.
//
#include <iostream>
using namespace std;

namespace leetcode450{
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        // 先查后访问
        if(root->val == key){
            // 删除
            // 情况1：叶子节点
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            } else if(root->left == nullptr || root->right == nullptr){ // 情况2：只有一个孩子，孩子直接往上顶
                TreeNode* rtn;
                if(root->left != nullptr){
                    return root->left;
                } else if(root->right != nullptr){
                    return root->right;
                }
            } else { // 情况3：有左右孩子。找到左孩子中的最大，或者右孩子中的最小，往上顶
                // 找到做孩子中的最大，然后往上顶后，再找
                TreeNode* rtn;
                rtn = getMax(root->left);
                deleteNode(root, rtn->val);
                root->val = rtn->val;
                return root;
            }
        } else if(root->val < key){
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
    TreeNode* getMax(TreeNode *root){
        auto rtn = root;
        while(rtn->right != nullptr) rtn = rtn->right;
        return new TreeNode(rtn->val);
    }
};
}