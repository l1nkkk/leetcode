//
// Created by l1nkkk on 2021/7/24.
//
#include <iostream>
#include <list>
#include <queue>
using namespace std;

namespace leetcode897{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
constexpr int null = -1;

TreeNode* Build(initializer_list<int > data){
    auto it = data.begin();
    queue<TreeNode*> qt;
    auto root = new TreeNode(*it);
    qt.push(root);
    ++it;
    while(!qt.empty() && it != data.end()){
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
        if(it == data.end()) break;
        if(*it != null){
            tn->right = new TreeNode(*it);
            ++it;
            qt.push(tn->right);
        }else{
            tn->right = nullptr;
            ++it;
        }
    }
    return root;
}
class Solution {
public:
    TreeNode* pre = nullptr;
    TreeNode* res = nullptr;
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        increasingBST(root->left);

        if(res == nullptr) res = root;
        root->left = nullptr;
        if(pre != nullptr){
            pre->right = root;
        }

        pre = root;
        increasingBST(root->right);
        return res;
    }
};


void test(){
    Solution s;
    auto tb = Build({2,1,4,null,null,3});
    auto res = s.increasingBST(tb);
}
}
