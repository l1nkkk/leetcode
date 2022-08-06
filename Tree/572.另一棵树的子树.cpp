//
// Created by l1nkkk on 2022/3/14.
//

#include <iostream>
#include <queue>
//#include
using namespace std;

namespace leetcode572{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    char null = '#';
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
    static constexpr char null = '#';
    string subStr = "";
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // idea: 后序遍历
        subStr = toString(subRoot);
        return dfs(root) == subStr;

    }

    string toString(TreeNode* root){
        if(root == nullptr) return string(1,null);
        return toString(root->left) + ',' + toString(root->right) + ',' + to_string(root->val);
    }

    // def：如果成功，返回 subStr
    string dfs(TreeNode* root){
        if(root == nullptr) return "#";
        auto lres =  dfs(root->left);
        if(lres == subStr) return subStr;
        auto rres = dfs(root->right);
        if(rres == subStr) return subStr;
        return lres + ',' + rres + ',' + to_string(root->val);
    }

};



void test(){
    auto input1 = Build({3,4,5,1,2});
    auto input2 = Build({4,1,2});
    Solution s;
    cout << s.isSubtree(input1,input2);
}

}