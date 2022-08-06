//
// Created by l1nkkk on 2021/8/25.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

namespace leetcode147{
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dumpHead = new ListNode(0,head);

        ListNode *cur = head->next;
        ListNode *lastSorted = head;
        while(cur){
            if(lastSorted->val <= cur->val){
                lastSorted = lastSorted->next;
            }
            else{
                ListNode *it = dumpHead->next;
                ListNode *pre = dumpHead;
                while(it != cur && it->val < cur->val){
                    it = it->next;
                    pre = pre->next;
                }
                pre->next = cur;
                lastSorted->next = cur->next;
                cur->next = it;
            }
            cur = lastSorted->next;
        }
        return dumpHead->next;
    }
};
void test(){
    auto input = Build({4,2,1,3});
    Solution s;
    auto res = s.insertionSortList(input);
    cout << "test";
}
}