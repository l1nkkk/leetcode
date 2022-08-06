//
// Created by l1nkkk on 2021/8/23.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer22 {
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* quick = head;
        while(--k){
            quick = quick->next;
        }

        ListNode* slow = head;
        while(quick){
            quick = quick->next;
            slow = slow->next;
        }
        return slow;
    }
};

}