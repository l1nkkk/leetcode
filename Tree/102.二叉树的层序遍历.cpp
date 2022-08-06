//
// Created by l1nkkk on 2021/8/19.
//

#include <iostream>
#include <queue>
using namespace std;

namespace leetcode102{
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        res.push_back({root->val});

        while(!q.empty()){
            auto num = q.size();
            vector<int> temp;
            while(num){
                auto t = q.front();

                q.pop();
                if(t->left){
                    q.push(t->left);
                    temp.push_back(t->left->val);
                }

                if(t->right){
                    q.push(t->right);
                    temp.push_back(t->right->val);
                }
                --num;
            }
            if(!temp.empty()){
                res.push_back(temp);
            }
        }
        return res;
    }
};

void test(){
    Solution s;
    auto input = Build({1,2,3,4,5});
    auto res = s.levelOrder(input);
    cout <<res.size();
}
}