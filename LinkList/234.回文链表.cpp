//
// Created by l1nkkk on 2021/7/23.
//

namespace leetcode234{
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }
    ListNode* left;
    bool traverse(ListNode *head){
        if(head == nullptr) return true;
        if(!traverse(head->next)){
            return false;
        }
        if(left->val == head->val) {
            left =left->next;
            return true;
        }

        return false;
    }
};
}