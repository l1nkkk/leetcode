//
// Created by l1nkkk on 2022/3/28.
//
#include <iostream>
#include <list>
#include <string>
#include <queue>
using namespace std;


namespace offer37{
constexpr  char null = '#';
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";
        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> items;
        // 1. 切割
        int it = 0;
        while(it < data.size()){
            auto p = data.find_first_of(',',it);
            items.push_back(data.substr(it,p-it));
            if(p != data.npos)
                it = ++p;
            else
                break;
        }
        return deserialize_(items);
    }

    TreeNode* deserialize_(list<string>& items){
        // 1. 取第一个为根
        auto t = items.front();
        items.pop_front();
        if(t == "#") return nullptr;
        auto root = new TreeNode(atoi(t.c_str()));

        // 2. 左右子树
        auto left = deserialize_(items);
        auto right = deserialize_(items);

        // 3. 连接左右字数
        root->left = left;
        root->right = right;
        return root;
    }
};

void test(){
    Codec c;
    auto t = Build({1,2,3,null,null,4,5});
    auto str =  c.serialize(t);
    cout << str << endl;
    auto res = c.deserialize(str);
    cout <<  res;
}
}