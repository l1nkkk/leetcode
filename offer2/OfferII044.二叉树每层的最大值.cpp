//
// Created by l1nkkk on 2022/7/31.
//
#include <vector>
#include <queue>
#include <climits>
using namespace std;

namespace offer2_44{
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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<int> res;
        while(!que.empty()){
            int n = que.size();
            int maxx = INT_MIN;
            while(n > 0){
               auto node = que.front();
               que.pop();
               if(node->left != nullptr){
                que.push(node->left);
               }
               if(node->right != nullptr){
                   que.push(node->right);
               }
               if(maxx < node->val){
                   maxx = node->val;
               }
                --n;
            }
            res.push_back(maxx);
        }
        return res;
    }
};
}
