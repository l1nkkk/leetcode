//
// Created by l1nkkk on 2021/7/13.
//
#include <iostream>
using namespace std;

namespace leetcode116{
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
Node* init(){
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);

    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
}
class Solution {
public:
    // 定义：将left和right连接起来
    void connectTwoNode(Node* node1, Node* node2){
        if(node1 == nullptr || node2 == nullptr)
            return;
        node1->next = node2;

        connectTwoNode(node1->left, node1->right);
        connectTwoNode(node2->left, node2->right);
        // 跨越父节点的两个表兄弟节点
        connectTwoNode(node1->right, node2->left);
    }
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        connectTwoNode(root->left, root->right);
        return root;
    }
};
}