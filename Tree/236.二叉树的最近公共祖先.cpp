//
// Created by l1nkkk on 2021/7/23.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace leetcode236{


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> rcp;
        vector<TreeNode*> rcq;
        bool pres = false, qres =  false;
        find(root, p, rcp, pres);
        find(root, q, rcq, qres);

        // 找最近的
        int posp = rcp.size()-1;
        int posq = rcq.size()-1;
        while(posp >= 0 && posq >= 0){
            if(rcp[posp] == rcq[posq]){
                --posp;
                --posq;
            } else{
                break;
            }
        }
        return rcp[posp+1];
    }

    bool find(TreeNode* root, TreeNode* target, vector<TreeNode*> &record, bool &res){
        if(root == nullptr || res) return res;

        if(root->val == target->val) {
            record.push_back(root);
            return true;
        }
        res = res || find(root->left, target, record, res) ;
        res = res || find(root->right, target, record, res)  ;
        if(res){
            record.push_back(root);
        }
        return res;
    }
};

class Solution1 {
public:
    // 定义:
    // 如果p和q在root为根的树中，返回lca
    // 如果只有一个在，返回root
    // 都不在，返回nullptr
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;

        TreeNode* left, *right;
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);

        /** 后序遍历，自带自底向上特性，所以root一定是lca*/
        if(left != nullptr && right != nullptr)
            return root;

        if(left == nullptr && right == nullptr)
            return nullptr;

        return left == nullptr? right:left;
    }
};

void test(){
    Solution s;
    auto tr = Build({3,5,1,6,2,0,8,null,null,7,4});
    cout << s.lowestCommonAncestor(tr, new TreeNode(5), new TreeNode(1))->val;
}


}