//
// Created by l1nkkk on 2021/8/18.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

namespace leetcode103{
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<vector<int>> res;
        list<TreeNode* > record;
        record.push_back(root);
        res.push_back({root->val});

        int flag = 1;
        while(!record.empty()){
            vector<int> temp;
            temp.clear();
            int num = record.size();
            if(flag == 1){
                flag = 0;
                while(num){
                    auto t = record.front();
                    record.pop_front();
                    if(t->right){
                        temp.push_back(t->right->val);
                        record.push_back(t->right);
                    }

                    if(t->left) {
                        temp.push_back(t->left->val);
                        record.push_back(t->left);
                    }
                    --num;
                }
            }else{
                flag = 1;
                while(num){
                    auto t = record.back();
                    record.pop_back();
                    if(t->left) {
                        temp.push_back(t->left->val);
                        record.push_front(t->left);
                    }

                    if(t->right){
                        temp.push_back(t->right->val);
                        record.push_front(t->right);
                    }
                    --num;
                }
            }
            if(!temp.empty())
                res.push_back(temp);

        }
        return res;
    }
};

void test(){
    Solution s;
    auto t = Build({0,2,4,1,null,3,-1,5,1,null,6,null,8});
    auto res = s.zigzagLevelOrder(t);
    cout << res.size();
}
}