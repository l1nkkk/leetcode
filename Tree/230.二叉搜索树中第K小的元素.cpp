//
// Created by l1nkkk on 2021/7/19.
//
#include <vector>
using namespace std;

namespace leetcode230 {
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
    vector<int> res;
    int kthSmallest(TreeNode *root, int k) {
        tarverse(root);
        return res[k-1];
    }

    void tarverse(TreeNode *root){
        if(root == nullptr) return;
        tarverse(root->left);
        res.push_back(root->val);
        tarverse(root->right);
    }

};
}