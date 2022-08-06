//
// Created by l1nkkk on 2021/10/13.
//

#include <iostream>
#include <stack>
using namespace std;
struct TreeNode{
    TreeNode(int v):val(v){};
    int val;
    TreeNode* left = nullptr,*right = nullptr;
};

void preOrder(TreeNode* root){
    if(root == nullptr)
        return;
    cout << root->val;
    preOrder(root->left);
    preOrder(root->right);
}

void preOrder_v1(TreeNode* root){
    if(root == nullptr) return;
    stack<TreeNode*> stkl; // 未被遍历
    stack<TreeNode*> stkr;
    stkl.push(root);
    while(!stkl.empty() || !stkr.empty()){
        if(!stkl.empty() ){
            auto t = stkl.top();
            stkl.pop();
            cout << t->val;
            if(t->left != nullptr)
                stkl.push(t->left);
            if(t->right != nullptr)
                stkr.push(t->right);
        }else {
            auto t = stkr.top();
            stkl.pop();
            cout << t->val;
            if(t->left != nullptr)
                stkl.push(t->left);
            if(t->right != nullptr)
                stkr.push(t->right);
        }
    }

}