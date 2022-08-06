//
// Created by l1nkkk on 2021/10/18.
//

#include <iostream>
using namespace std;

namespace leetcode24{


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
    ListNode* h = nullptr;
    ListNode* record = nullptr;
    ListNode* reverseN(ListNode* head, int n){
        if(head == nullptr)
            return nullptr;
        if(n == 1 ){
            record = head->next;
            h = head;
            return h;
        }

        ListNode* t;
        if( (t = reverseN(head->next, n-1))!= nullptr){
            head->next->next = head;
            head->next = record;
            return h;
        }else
            return head;
    }

//    [l,r)
    ListNode* reverseRange(ListNode* head, int l, int r){
        if(l != 0){
            head->next = reverseRange(head->next, l-1, r-1);
        }else{
            head = reverseN(head, r);
        }
        return head;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        int size = 0;
        ListNode* it = head;
        while (it){
            it = it->next;
            size++;
        }

        it = head;
        for(int i = 0; i < size; i+=2){
            h = nullptr;
            record = nullptr;
            it = reverseRange(it, i, i+2);
        }
        return it;
    }
};

void test(){
    auto input = Build({1,2,3});
    Solution s;
    auto res = s.swapPairs(input);
    cout << "test";
}
}