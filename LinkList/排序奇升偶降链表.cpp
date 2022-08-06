//
// Created by l1nkkk on 2022/3/8.
//
#include <iostream>
#include <initializer_list>
#include <assert.h>
using namespace std;
namespace add1{
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    // 奇偶链表拆分
    void oddEvenList(ListNode* head, ListNode*& h1, ListNode*& h2){
        ListNode *it1, *it2;
        h1 = head;
        h2 = head->next;
        it1 = h1;
        it2 = h2;

        while(it1 != nullptr && it2 != nullptr){
            if(it1->next == it2){
                it1->next = it2->next;
                if(it1->next == nullptr)// 偶数个
                    break;
                else
                    it1 = it2->next;
            }else{
                it2->next = it1->next;
                if(it2->next == nullptr)// 奇数个
                    break;
                else
                    it2 = it1->next;
            }
        }
        return;
    }

    // 反转链表
    ListNode* reverse(ListNode* node){
        if(node->next == nullptr)
            return node;

        auto rtn = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return rtn;
    }

    ListNode* mergeByorder(ListNode* lp, ListNode* rp){
        ListNode* rtn = nullptr, *it = nullptr;
        while(lp != nullptr && rp != nullptr){
            auto t = lp->val < rp->val ? lp : rp;
            if(!rtn) {
                rtn = t;
                it = t;
            } else{
                it->next = t;
                it = it->next;
            }
            lp->val < rp->val ? lp=lp->next : rp=rp->next;
        }

        // 链表直接接上去就行了，不用循环
        ListNode* t;
        if(lp == nullptr) it->next = rp;
        else it->next = lp;
        assert(it->next != nullptr);


        return rtn;
    }

    ListNode* solve(ListNode* head) {
        if(head == nullptr) return nullptr;
        // 1. 奇偶链表
        ListNode* h1, *h2;
        oddEvenList(head, h1, h2);

        // 2. 反转链表
        h2 = reverse(h2);

        // 3. merge
        auto rtn = mergeByorder(h1, h2);
        return rtn;
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

void show(ListNode* res ){
    while(res){
        cout << res->val <<" ";
        res = res->next;
    }
}

void test(){
    auto input = Build({1,8,3,6,5,4,7,2});
    Solution s;
    auto rtn = s.solve(input);
    show(rtn);
}
}
