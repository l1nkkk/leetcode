//
// Created by l1nkkk on 2021/9/2.
//

#include <iostream>
#include <queue>
using namespace std;
namespace leetcode958{

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
        if(it == data.end())
            break;
        if(*it != null){
            tn->right = new TreeNode(*it);
            ++it;
            qt.push(tn->right);
        }else{
            tn->right = nullptr;
            ++it;
        }
        if(it == data.end())
            break;
    }
    return root;
}



class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        bool flag = true;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            while (n){
                auto t = que.front();
                que.pop();
                if(t->left != nullptr){
                    if(!flag)
                        return false;
                    que.push(t->left);
                }else{
                    flag = false;
                }
                if(t->right != nullptr){
                    if(!flag)
                        return false;
                    que.push(t->right);
                }else{
                    flag = false;
                }
                --n;
            }
        }
        return true;
    }
};
void test(){
    auto input = Build({1,2,3,4,5,null,7});
    Solution s;
    cout << s.isCompleteTree(input) << endl;

}
}