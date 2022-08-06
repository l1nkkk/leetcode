//
// Created by l1nkkk on 2021/9/13.
//
#include <iostream>
#include <queue>
using namespace std;

namespace leetcode662{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
constexpr int null = -3;

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = 0;
        int pad = 0;
        queue<TreeNode*> que;

        root->val = 1;
        que.push(root);

        while(!que.empty()){
            res = max(res, que.back()->val - que.front()->val + 1);

            int n = que.size();
            pad = que.front()->val; // 重点：将最左边节点，从0开始计数
            while(n){
                auto node = que.front();
                que.pop();
                node->val -= pad;
                if(node->left != nullptr) {
                    node->left->val = node->val * 2 ;
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    node->right->val = node->val * 2 + 1;
                    que.push(node->right);
                }
                --n;
            }
        }
        return res;
    }
};

void test(){
    auto root = Build({1,3,2,5,3,null, 9});
    Solution s;
    cout << s.widthOfBinaryTree(root);
}

}