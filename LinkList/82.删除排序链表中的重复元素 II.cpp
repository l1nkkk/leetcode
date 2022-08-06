//
// Created by l1nkkk on 2021/8/25.
//

#include <iostream>
#include <string>
using namespace std;

namespace leetcode82{
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* Build(initializer_list<int> data){
    ListNode* head = nullptr;
    ListNode* pre = nullptr;

    for(auto &it: data){
        if(head == nullptr){
            head = new ListNode(it);
            pre = head;
        }
        else {
            pre->next = new ListNode(it);
            pre = pre->next;
        }
    }
    return head;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *slow, *fast;
        ListNode *drumpHead = new ListNode(head->val-1, head);
        slow = drumpHead;
        fast = head->next;
        while(fast != nullptr){
            if(slow->next->val != fast->val){
                if(slow->next->next == fast){
                    slow = slow->next;
                }else{
                    slow->next = fast;
                }
            }
            fast = fast->next;
        }
        if(slow->next->next != nullptr)
            slow->next = nullptr;
        return drumpHead->next;
    }
};

void test(){
    auto input = Build({1, 2, 3, 3, 4, 4, 5});
    Solution s;
    auto res = s.deleteDuplicates(input);
    cout <<"test";
}
}