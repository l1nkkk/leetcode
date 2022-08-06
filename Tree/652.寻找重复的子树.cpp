//
// Created by l1nkkk on 2021/7/15.
//

#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;

namespace leetcode652{
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
    // 定义：
    vector<TreeNode*> res;
    map<string, TreeNode*> mst;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        if(root == nullptr) return res;
        traverse(root);
        return res;
    }
    string traverse(TreeNode* root){
        if(root == nullptr) return "#";
        string rtn;
        rtn += traverse(root->left) + ",";
        rtn += traverse(root->right)+ ",";
        rtn += to_string(root->val);
        /** 后序遍历位置*/
        if(mst.find(rtn) == mst.end()) {
            mst[rtn] = root;
        }else{
            if(mst[rtn] != nullptr) {
                res.push_back(mst[rtn]);
                mst[rtn] = nullptr;
            }
        }

        return rtn;
    }
};
}