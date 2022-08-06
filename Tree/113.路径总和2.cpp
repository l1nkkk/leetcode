//
// Created by l1nkkk on 2021/9/11.
//
#include <vector>
using namespace std;
namespace leetcode113{
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
    vector<int> curRecord;
    vector<vector<int>> res{};
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return {};
        dfs(root, targetSum);
        return res;
    }
    void dfs(TreeNode* root, int targetSum){
        if(root == nullptr) return;

        curRecord.push_back(root->val);
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);

        if(root->left == nullptr && root->right == nullptr && targetSum == root->val){
            res.push_back(curRecord);
        }
        curRecord.pop_back();

    }
};
}