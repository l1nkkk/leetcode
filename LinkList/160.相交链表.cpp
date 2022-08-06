//
// Created by l1nkkk on 2021/8/10.
//

#include <iostream>
#include <unordered_set>
using namespace std;

namespace leetcode160{
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while(headA != nullptr){
            s.insert(headA);
            headA = headA->next;
        }
        while(headB != nullptr){
            if(s.count(headB))
                return headB;
            s.insert(headB);
            headB = headB->next;
        }
        return nullptr;
    }
};


}