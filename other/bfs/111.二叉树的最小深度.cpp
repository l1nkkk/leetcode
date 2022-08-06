//
// Created by l1nkkk on 2021/8/4.
//

#include <iostream>
#include <queue>

using namespace std;

namespace leetcode111{

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        int depth = 1;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; ++i){
                auto node = q.front();
                q.pop();

                if(node->left == nullptr && node->right == nullptr)
                    return depth;
                if(node->left != nullptr){
                    q.push(node->left );
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            ++depth;
        }
        return depth;
    }
};
const int null = -1;
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


void test(){
    auto rt = Build({3,9,20,null,null,15,7});
    Solution s;
    cout <<s.minDepth(rt);
}
}