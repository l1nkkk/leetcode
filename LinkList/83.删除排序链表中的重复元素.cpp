//
// Created by l1nkkk on 2021/7/26.
//
#include <iostream>


namespace leetcode83{
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *slow,*fast;

        slow = head;
        fast = head;
        while(fast != nullptr){
            if(slow->val != fast->val){
                slow = slow->next;
                slow->val = fast->val;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};
}