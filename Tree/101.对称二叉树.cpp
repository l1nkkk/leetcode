//
// Created by l1nkkk on 2021/9/2.
//

#include <iostream>
#include <queue>

using namespace std;

namespace leetcode101{

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

constexpr int null = -1;
TreeNode* Build(initializer_list<int > data){
    auto it = data.begin();
    queue<TreeNode*> qt;
    auto root = new TreeNode(*it);
    qt.push(root);
    ++it;
    while(!qt.empty()&&it != data.end()){
        auto tn = qt.front();
        qt.pop();
        // 左孩子
        if(*it != null){
            tn->left = new TreeNode(*it);
            ++it;
            qt.push(tn->left);
        }else{
            tn->left = nullptr;
            ++it;
        }
        if(it == data.end())
            break;
        if(*it != null){
            tn->right = new TreeNode(*it);
            ++it;
            qt.push(tn->right);
        }else{
            tn->right = nullptr;
            ++it;
        }
        if(it == data.end())
            break;
    }
    return root;
}


class Solution {
public:
    vector<string> res;
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)return true;
        return dfs(root->left, root->right);
    }
    bool dfs(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr)
            return true;
        if(left == nullptr || right == nullptr)
            return false;
        if(left->val == right->val)
            return dfs(left->left, right->right) && dfs(left->right, right->left);
        return false;

    }
};

void test(){
    auto input = Build({1,2,2,3,4,4,3});
    Solution s;
    cout << s.isSymmetric(input) << endl;

}
}