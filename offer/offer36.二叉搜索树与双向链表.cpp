//
// Created by l1nkkk on 2021/9/13.
//
#include <iostream>
using namespace std;


namespace offer36{
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* head = nullptr;
    Node* pre = nullptr;
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        dfs(root);
        return head;
    }
    void dfs(Node* root){
        if(root == nullptr) return;
        dfs(root->left);
        if(head == nullptr){
            head = root;
        }
        if(pre != nullptr){
            pre->right = root;
        }
        root->left = pre;
        pre = root;
        dfs(root->right);
    }
};

Node* Build(){
    Node* lroot = new Node(4);
    Node* l11 = new Node(2);
    Node* l12 = new Node(5);
    lroot->left = l11;
    lroot->right = l12;

    Node* l21 = new Node(1);
    Node* l22 = new Node(3);

    l11->left = l21;
    l11->right = l22;
    return lroot;

}

void test(){
    auto root = Build();
    Solution s;
    auto res = s.treeToDoublyList(root);
    cout << "test" << endl;
}
}