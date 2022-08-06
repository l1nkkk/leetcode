//
// Created by l1nkkk on 2021/8/29.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace leetcode337{
constexpr int null = -1;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
    int rob(TreeNode* root) {
        auto rtn = dfs(root);
        return max(rtn.first, rtn.second);
    }
    // first,以其为跟的最大。 second，不以其为根的最大
    pair<int, int> dfs(TreeNode* root){
        if(root == nullptr) return{0,0};
        auto leftrtn = dfs(root->left);
        auto rightrtn = dfs(root->right);
        pair<int,int > res;
        res.first = leftrtn.second + rightrtn.second + root->val;
        res.second = max(leftrtn.second,leftrtn.first) + max(rightrtn.second, rightrtn.first);
        return res;

    }
};

void test(){
    auto input = Build({3,2,3,null,3,null,1});
    Solution s;
    auto res = s.rob(input);
    cout << res;
}
}