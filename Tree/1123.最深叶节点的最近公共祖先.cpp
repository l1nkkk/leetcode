//
// Created by l1nkkk on 2022/3/12.
//
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
namespace leetcode1123{
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // idea：1.求深度的递归 2.用一个成员记录路径，用另一个成员来记录最深叶节点的路径 3.判断最近祖先的方法：找到路径最后一个相同的
        dfs(root);
        if(record.size() == 1){
            return record[0].back();
        }
        for(int i = 0; i < record[0].size(); ++i){
            TreeNode* cmpBase = record[0][i];
            int j = 1;
            while( j < record.size()){
                if(cmpBase != record[j][i])
                    break;
                ++j;
            }

            if(record.size() != j)
                return record[0][i-1];
        }
        return record[0].back();
    }
    vector<vector<TreeNode*> > record;
    vector<TreeNode*> path;
    int curH=0, maxH = 0;
    // define: 遍历树，如果是叶子节点，并且是目前最大深度，则记录
    void dfs(TreeNode* root){
        if(!root) return;
        ++curH;
        path.push_back(root);
        dfs(root->left);
        dfs(root->right);
        --curH;

        if(root->left == nullptr && root->right == nullptr){
            // 如果是叶子节点
            if(curH == maxH){
                record.push_back(path);
            }else if(curH > maxH){
                maxH = curH;
                record.clear();
                record.push_back(path);
            }
        }
        path.pop_back();
    }
};


void test(){
    Solution s;
//    auto root = Build({3,5,1,6,2,0,8,null,null,7,4});
    auto root = Build({1});
    auto res = s.lcaDeepestLeaves(root);
    cout <<res->val;
}

}