//
// Created by l1nkkk on 2021/8/19.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace leetcode124{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
constexpr int null = INT32_MIN;
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
    int res = INT32_MIN;
    // 定义：后序遍历，返回包含该节点最多可以加成多少。注意返回时只能选择左边或者右边
    int dfs(TreeNode* root){
        if(root == nullptr)return 0;
        auto lrtn = dfs(root->left);
        auto rrtn = dfs(root->right);
        int rtn;

        if(lrtn <= 0 && rrtn <= 0)
            rtn = root->val;
        else if(lrtn > 0 && rrtn > 0){
            rtn = lrtn + rrtn + root->val;
        } else if(lrtn > 0){
            rtn = lrtn+ root->val;
        } else if(rrtn > 0){
            rtn = rrtn + root->val;
        }

        if(rtn > res){
            res = rtn;
        }

        // 重要：补丁，如果父节点要包含该节点，则该节点不能分叉
        if(lrtn > 0 && rrtn > 0){
            rtn -= lrtn < rrtn ? lrtn : rrtn;
        }
        return rtn;

    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

};

void test(){
    Solution s;
    auto input = Build({5,4,8,11,null,13,4,7,2,null,null,null,1});
    cout << s.maxPathSum(input) << endl;
    cout <<"tes";
}
}