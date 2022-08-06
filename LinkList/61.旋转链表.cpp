//
// Created by l1nkkk on 2021/11/11.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
namespace leetcode61{
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode *slow, *fast;
        int record,len;

        slow = head;
        fast = head;
        while(k){
            fast = fast->next;
            ++record;
            --k;
            if(fast == nullptr) {
                len = record; // 链表长度
                k %= len;       // 减少接下来循环次数
                fast = head;
            }
        }

        // 原链表不需要改变的情况
        if(fast == slow) return head;

        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        auto temp = slow->next;
        slow->next  = nullptr;
        fast->next = head;
        return temp;
    }
};
}