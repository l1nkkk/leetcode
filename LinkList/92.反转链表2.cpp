//
// Created by l1nkkk on 2021/7/13.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode92 {

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *success;
    // 反转前n个节点,返回反转后的头结点
    ListNode *reverseN(ListNode *head, int n) {
        if(n == 1){
            success = head->next;
            return head;
        }
        ListNode * tail = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = success;
        return tail;
    }

    // 反转【left,right】区间的节点，返回反转后的头结点
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if(left == 1){
            return reverseN(head,right);
        }
        head->next = reverseBetween(head->next, left-1, right-1);
        return head;
    }

};

ListNode* init(vector<int> datas){
    ListNode* head = nullptr;
    ListNode* last = nullptr;
    for(auto d : datas){
        if(head == nullptr) {
            head = new ListNode(d, nullptr);
            last = head;
        }
        else{
            last->next = new ListNode(d, nullptr);
            last = last->next;
        }
    }
    return head;
}
}