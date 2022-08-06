//
// Created by l1nkkk on 2021/8/30.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace leetcode110{
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
    int depth(TreeNode* root){
        if(root == nullptr) return 0;
        int leftv = depth(root->left);
        if(leftv == -1) return -1;
        int rightv = depth(root->right);
        if(rightv == -1) return -1;
        if(abs(leftv - rightv) >=2){
            return -1;
        }
        return max(leftv, rightv)+1;
    }
    bool isBalanced(TreeNode* root) {

        return depth(root) != -1;
    }
};
void test(){
    auto input = Build({1,2,2,3,3,null,null,4,4});
    Solution s;
    cout << s.isBalanced(input);

}
}