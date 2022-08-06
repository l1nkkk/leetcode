//
// Created by l1nkkk on 2022/3/8.
//
#include <iostream>
#include <initializer_list>
using namespace std;
namespace leetcode328{
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *it1, *it2, *h1, *h2;
        h1 = head;
        h2 = head->next;
        it1 = h1;
        it2 = h2;

        while(it1 != nullptr && it2 != nullptr){
            if(it1->next == it2){
                // it1 在后
                it1->next = it2->next;
                if(it1->next == nullptr)
                    break;// 偶数个情况
                else
                    it1 = it1->next;
            }else{
                // it2 在后
                it2->next = it1->next;
                if(it2->next == nullptr)
                    break;// 奇数个情况
                else
                    it2 = it2->next;
            }
        }

        it1->next = h2;

        return h1;
    }
};

void test(){
    auto input = Build({2,1,3,5,6,4,7});
    Solution s;
    auto res = s.oddEvenList(input);

    while(res){
        cout << res->val <<" ";
        res = res->next;
    }
}

}