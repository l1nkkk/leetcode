//
// Created by l1nkkk on 2021/8/23.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode2{
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr, *resit=nullptr;
        ListNode *it1,*it2;
        it1 = l1;
        it2 = l2;
        int n = 0;
        while(it1 != nullptr && it2 != nullptr){
            it1->val= it1->val + it2->val + n;
            n = it1->val /10;
            it1->val %= 10;
            if(res == nullptr){
                res = it1;
                resit = it1;
            }else{
                resit->next = it1;
                resit = resit->next;
            }
            it1 = it1->next;
            it2 = it2->next;
        }
        while(it1 != nullptr){
            resit->next = it1;
            resit = resit->next;
            resit->val += n;
            n = resit->val /10;
            resit->val %= 10;

            it1 = it1->next;
        }

        while(it2 != nullptr){
            resit->next = it2;
            resit = resit->next;
            resit->val += n;
            n = resit->val /10;
            resit->val %= 10;

            it2 = it2->next;
        }

        if(n == 1){
            resit->next = new ListNode(1);
        }
        return res;
    }
};

void test(){
    auto l1 = Build({2,4,3});
    auto l2 = Build({5,6,4});
    Solution s;
    auto res = s.addTwoNumbers(l1,l2);
    cout << "test";
}
}