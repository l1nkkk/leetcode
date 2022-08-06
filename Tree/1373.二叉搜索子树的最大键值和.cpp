//
// Created by l1nkkk on 2021/7/22.
//
#include <iostream>
#include <list>
#include <queue>
using namespace std;
namespace leetcode1373 {
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
    while(!qt.empty()){
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
    int maxSumBST(TreeNode *root) {
        deal(root);
        return res;
    }

    static constexpr int FALSE=111111;
    int res = 0;
    // 定义：判断是不是BST ，返回FALSE表明不是，否则返回累加和
    int deal(TreeNode* root){
        if(root == nullptr) return 0;
        // 判断左右是不是BST
        auto lres = deal(root->left);
        auto rres = deal(root->right);
        if(lres == FALSE || rres == FALSE) return FALSE;

        // 判断自己是不是BST
        int lmax, rmin;
        if(root->left != nullptr){
            lmax = getMax(root->left);
            if(lmax >= root->val) return FALSE;
        }
        if(root->right != nullptr){
            rmin = getMin(root->right);
            if(rmin <= root->val) return FALSE;
        }

        res = res < root->val + lres + rres ? root->val + lres + rres :res;
        return root->val + lres + rres;
    }
    int getMax(TreeNode *root){
        auto tm = root;
        int rtn;
        while(tm!= nullptr){
            rtn = tm->val;
            tm = tm->right;
        }
        return rtn;
    }

    int getMin(TreeNode *root){
        auto tm = root;
        int rtn;
        while(tm!= nullptr){
            rtn = tm->val;
            tm = tm->left;
        }
        return rtn;
    }

};

void test(){
    auto rtn = Build({1,4,3,2,4,2,5,null,null,null,null,null,null,4,6,null,null,null,null});
    Solution s;
    std::cout << s.maxSumBST(rtn);
}
}