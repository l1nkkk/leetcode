//
// Created by l1nkkk on 2021/7/20.
//


namespace leetcode98 {
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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, nullptr, nullptr);
    }
    // 递归定义：只负责判断当前node符不符合，符合返回true
    bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {
        if(root == nullptr) return true;

        /**前序遍历*/
        if(min != nullptr && root->val <= min->val) return false;
        if(max != nullptr && root->val >= max->val) return false;

        return isValidBST(root->left, min, root) &&
                isValidBST(root->right, root, max);
    }
};

class Solution1 {
public:

    // 递归定义：如果是BST返回true。
    bool isValidBST(TreeNode *root) {
        if(root == nullptr) return true;

        auto lres = isValidBST(root->left);
        auto rres = isValidBST(root->right);
        if(!lres || !rres) return false;
        /**后序处理*/
        int lmax, rmin;
        if(root->left != nullptr){
            lmax = getMax(root->left);
            if(lmax >= root->val) return false;
        }

        if(root->right != nullptr){
            rmin = getMin(root->right);
            if(rmin <= root->val) return false;
        }
        return true;
    }

    int getMax(TreeNode* root){
        auto tn = root;
        while(tn->right != nullptr){
            tn = tn->right;
        }
        return tn->val;
    }
    int getMin(TreeNode* root){
        auto tn = root;
        while(tn->left != nullptr){
            tn = tn->left;
        }
        return tn->val;
    }

};
}