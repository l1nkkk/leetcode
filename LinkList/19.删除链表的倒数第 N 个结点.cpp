//
// Created by l1nkkk on 2021/7/24.
//

namespace leetcode19{
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        ListNode* fast,*slow;
        fast = head;
        slow = head;
        while(n > 0){
            fast = fast->next;
            --n;
        }
        // 删除的是第一个
        if(fast == nullptr){
            return head->next;
        }
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
}