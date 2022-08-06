//
// Created by l1nkkk on 2021/7/15.
//
#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

namespace leetcode297{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string resStr;
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        queue<TreeNode*> qtree;
        qtree.push(root);
        resStr += to_string(root->val)+ ',';

        while(!qtree.empty()){
            auto tempn = qtree.front();
            qtree.pop();
            if(tempn->left != nullptr){
                qtree.push(tempn->left);
                resStr += to_string(tempn->left->val) + ',';
            } else{
                resStr += "#,";
            }

            if(tempn->right != nullptr) {
                qtree.push(tempn->right);
                resStr += to_string(tempn->right->val)+ ',';
            }else {
                resStr += "#,";
            }
        }
        return resStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        vector<string> vs;
        // 处理data
        while(data.find(',') != string::npos){
            vs.push_back(data.substr(0,data.find(',')));
            if(data.find(',') == data.size()-1)
                break;
            data = data.substr(data.find(',')+1,data.size());
        }

        int pos = 0;
        queue<TreeNode*> qt;
        TreeNode* rtn = new TreeNode(stoi(vs[pos++]));
        qt.push(rtn);
        while(!qt.empty()){
            auto tempn = qt.front();
            qt.pop();

            // left
            if(vs[pos] == "#"){
                tempn->left = nullptr;
                ++pos;
            }else{
                tempn->left = new TreeNode(stoi(vs[pos++]));
                qt.push(tempn->left);
            }
            // right
            if(vs[pos] == "#"){
                tempn->right = nullptr;
                ++pos;
            }else{
                tempn->right = new TreeNode(stoi(vs[pos++]));
                qt.push(tempn->right);
            }
        }
        return rtn;
    }
};



TreeNode* Build(){
    TreeNode* rtn = new TreeNode(1);
    rtn->left = new TreeNode(2);
    rtn->right = new TreeNode(3);
    rtn->right->left = new TreeNode(4);
    rtn->right->right = new TreeNode(5);
    return rtn;
}


void test(){
    auto tree = Build();
    Codec c;
    cout << c.serialize(tree) << endl;
    auto res = c.deserialize(c.serialize(tree));

}
}