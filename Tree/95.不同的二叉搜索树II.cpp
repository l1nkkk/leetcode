//
// Created by l1nkkk on 2021/7/21.
//
#include <vector>
#include <iostream>
using namespace std;



namespace leetcode95{
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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
    // 1.选定根 2.递归左右子树 3.和根合并
    vector<TreeNode*> generateTrees(int lo, int hi) {
        vector<TreeNode*> rtn;
        if( lo > hi) return rtn;
        for(int i = lo; i <= hi; ++i){
            // 选定根i

            // 递归左右
            auto leftRes = generateTrees(lo, i-1);
            auto rightRes = generateTrees(i+1, hi);

            // 合并
            if(leftRes.size() == 0 && rightRes.size() == 0){
                auto root = new TreeNode(i);
                rtn.push_back(root);
            }
            else if(leftRes.size() == 0){
                for( auto rr : rightRes){
                    auto root = new TreeNode(i);
                    root->left = nullptr;
                    root->right = rr;
                    rtn.push_back(root);
                }
            } else if(rightRes.size() == 0){
                for( auto lr : leftRes){
                    auto root = new TreeNode(i);
                    root->left = lr;
                    root->right = nullptr;
                    rtn.push_back(root);
                }
            } else{
                for( auto lr : leftRes){
                    for( auto rr : rightRes){
                        auto root = new TreeNode(i);
                        root->left = lr;
                        root->right = rr;
                        rtn.push_back(root);
                    }
                }
            }
        }
        return rtn;
    }
};
}