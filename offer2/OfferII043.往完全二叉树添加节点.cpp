//
// Created by l1nkkk on 2022/7/31.
//
#include <cmath>
#include <stack>
using namespace std;

namespace offer2_43{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class CBTInserter {
public:
    CBTInserter(TreeNode* r) {
        this->root = r;
        size = getSize(r);
    }

    int insert(int v) {
        ++size;
        if(root == nullptr){
            root = new TreeNode(v);
        }
        stack<int> st;
        auto record = size;
        while(record != 1){
            record /= 2;
            st.push(record);
        }
        st.pop();
        auto it = root;
        while (!st.empty()){
            auto pos = st.top();
            st.pop();
            if(pos % 2 == 0){
                it = it->left;
            }else{
                it = it->right;
            }
        }
        if (size%2 == 0){
            it->left = new TreeNode(v);
        }else{
            it->right = new TreeNode(v);
        }
        return it->val;
    }


    TreeNode* get_root() {
        return root;
    }
    int getSize(TreeNode* root){
        if(root == nullptr) return 0;
        auto lh = getLeftHigh(root->left);
        auto rh = getRightHigh(root->right);
        if(lh == rh){
            // 满二叉树
            return pow(2,lh+1)-1;
        }
        return getSize(root->left) + getSize(root->right) + 1;

    }
    int getLeftHigh(TreeNode* root){
        int res = 0;
        while(root){
            ++res;
            root = root->left;
        }
        return res;
    }
    int getRightHigh(TreeNode* root){
        int res = 0;
        while(root){
            ++res;
            root = root->right;
        }
        return res;
    }

private:
    TreeNode* root = nullptr;
    int size = 0;
};
}