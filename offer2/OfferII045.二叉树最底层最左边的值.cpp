//
// Created by l1nkkk on 2022/7/31.
//

#include <iostream>
#include<queue>
using namespace std;
namespace offer2_45{
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while(!que.empty()){
            int n = que.size();
            res = que.front()->val;
            while(n > 0){
                --n;
                auto node = que.front();
                que.pop();
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
        }
        return res;
    }
};
}