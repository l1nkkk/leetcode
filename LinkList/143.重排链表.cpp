//
// Created by l1nkkk on 2021/8/23.
//

#include <deque>
#include <iostream>
#include <assert.h>
using namespace std;
namespace leetcode143{
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 法1
class Solution1 {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        deque<ListNode*> nodeq;
        ListNode *itn = head;
        while(itn != nullptr){
            nodeq.push_back(itn);
            itn = itn->next;
        }
        ListNode *lo;
        ListNode *hi;

        while(!nodeq.empty()){
            hi = nodeq.back();
            nodeq.pop_back();
            if(nodeq.empty()) break;

            lo = nodeq.front();
            nodeq.pop_front();

            hi->next = lo->next;
            lo->next = hi;
        }

        hi->next = nullptr;
    }
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
    ListNode* reverse(ListNode* head){
        if(head->next == nullptr)
            return head;
        auto rtn = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rtn;
    }

    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        if(head->next == nullptr) return;

        // 1. 找中点
        ListNode* fast = head, *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        // 截断成两条链表，左半部分和右半部分
        ListNode* p1,*p2;
        p1 = head;
        p2 = slow->next;
        slow->next = nullptr;// 截断

        // 2. 反转右部分的俩表
        p2 = reverse(p2);

        // 3. merge 链表
        ListNode* it = p1;
        bool flag = true;
        assert( it == head);
        while(p1 != nullptr && p2 != nullptr){
            if(flag){
                p1 = p1->next;
                it->next = p2;
                it = it->next;
                flag = false;
            }else{
                p2 = p2->next;
                it->next = p1;
                it = it->next;
                flag = true;
            }
        }
    }
};


void test(){
//    auto input = Build({1,2,3,4,5});
    auto input = Build({1,2});
    Solution s;
    s.reorderList(input);
    while(input){
        cout << input->val << " ";
        input = input->next;
    }
    cout <<"test";
}

}