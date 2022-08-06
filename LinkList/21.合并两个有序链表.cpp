//
// Created by l1nkkk on 2021/8/10.
//

#include <iostream>
#include <vector>
using namespace std;
namespace leetcode21{
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *left, *right;
        ListNode *it, *resHead;
        resHead = new ListNode();
        it = resHead;
        left = l1;
        right = l2;
        while(left != nullptr && right != nullptr){
            if(left->val <= right->val){
                it->next = left;
                left = left->next;
                it = it->next;
            }
            else{
                it->next = right;
                right = right->next;
                it = it->next;
            }
        }
        while(left != nullptr){
            it->next = left;
            left = left->next;
            it = it->next;
        }
        while(it != nullptr){
            it->next = right;
            right = right->next;
            it = it->next;
        }
        return resHead->next;
    }
};


}
