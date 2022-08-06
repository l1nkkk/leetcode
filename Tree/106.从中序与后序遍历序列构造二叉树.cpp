//
// Created by l1nkkk on 2021/7/14.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode106{
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
    TreeNode* build(vector<int>& inorder, int inStrat, int inEnd, vector<int>postorder, int postStart, int postEnd){
        if(inStrat > inEnd) return nullptr;

        TreeNode* rt = new TreeNode(postorder[postEnd]);
        // 找到in中的root
        int in_rt = inStrat;
        while(in_rt <= inEnd){
            if(inorder[in_rt] == postorder[postEnd]){
                break;
            }
            ++in_rt;
        }
        auto leftSize = in_rt - inStrat;
        rt->left = build(inorder, inStrat, in_rt-1, postorder, postStart, postStart+leftSize-1);
        rt->right = build(inorder, in_rt+1, inEnd, postorder, postStart+leftSize, postEnd-1);
        return rt;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 思路：先找到根节点，再分别构建根节点的左右子树。
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};

void test(){
    Solution s;
    vector<int> pre{3,2,1}, in{3,2,1};
    auto res = s.buildTree(pre,in);

}

}