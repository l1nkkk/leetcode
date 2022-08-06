//
// Created by l1nkkk on 2021/7/24.
//

namespace leetcode142{
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode* fast, *slow;
        fast = head;
        slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }

        slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            if(slow == fast) return slow;
            else{
                slow = slow->next;
                fast = fast->next;
            }
        }
        return nullptr;
    }
};
}