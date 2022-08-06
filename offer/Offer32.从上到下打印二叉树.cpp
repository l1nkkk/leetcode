//
// Created by l1nkkk on 2022/3/27.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

namespace offer32{

struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 1. 层序遍历，不记录层数
//class Solution {
//public:
//    vector<int> levelOrder(TreeNode* root) {
//        if(root == nullptr) return vector<int>();
//        queue<TreeNode*> qu;
//        qu.push(root);
//        vector<int> res;
//
//        while(!qu.empty()){
//            auto t = qu.front();
//            qu.pop();
//            res.push_back(t->val);
//            if(t->left != nullptr) qu.push(t->left);
//            if(t->right != nullptr) qu.push(t->right);
//        }
//        return res;
//    }
//};


// 2. 层序遍历，记录层数
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        if(root == nullptr) return vector<vector<int>>();
//        queue<TreeNode*> qu;
//        qu.push(root);
//        vector<vector<int>> res;
//        int sum;
//
//        while(!qu.empty()){
//            sum = qu.size();
//            vector<int> subres;
//            while(sum > 0) {
//                --sum;
//                auto t = qu.front();
//                qu.pop();
//                subres.push_back(t->val);
//                if(t->left != nullptr) qu.push(t->left);
//                if(t->right != nullptr) qu.push(t->right);
//            }
//            res.push_back(subres);
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return vector<vector<int>>();
        deque<TreeNode*> de;
        de.push_back(root);
        vector<vector<int>> res;
        int sum;
        bool flag = true;//

        while(!de.empty()){
            sum = de.size();
            vector<int> subres;
            while(sum){

                if(flag){
                    auto t = de.back(); de.pop_back();
                    subres.push_back(t->val);
                    if(t->right != nullptr) de.push_front(t->right);
                    if(t->left != nullptr) de.push_front(t->left);
                }else{
                    auto t = de.back(); de.pop_back();
                    subres.push_back(t->val);
                    if(t->left != nullptr) de.push_back(t->left);
                    if(t->right != nullptr) de.push_back(t->right);
                }
                --sum;
            }
            res.push_back(subres);
            flag = !flag;
        }
        return res;
    }
};



}