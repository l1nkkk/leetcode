//
// Created by l1nkkk on 2021/7/22.
//

#include <iostream>
#include <cmath>
using namespace std;

namespace leetcode222{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 普通二叉树的做法
class Solution {
public:
    int countNodes(TreeNode* root) {
        // base case
        if(root == nullptr) return 0;

        auto lres = countNodes(root->left);
        auto rres = countNodes(root->right);
        /**后序*/
        return 1 + lres + rres;
    }
};

class Solution1 {
public:
    int countNodes(TreeNode* root) {
        // base case
        if(root == nullptr) return 0;

        // 左边边
        int hl = 0;
        TreeNode* ln = root;
        while(ln != nullptr){
            ln = ln->left;
            ++hl;
        }
        // 右边边
        int hr = 0;
        TreeNode* rn = root;
        while(rn != nullptr){
            rn = rn->right;
            ++hr;
        }
        // man二叉树
        if(hr == hl){
            return pow(2, hr)-1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

//void test(){
//    Solution s;
//    s.countNodes();
//}

}