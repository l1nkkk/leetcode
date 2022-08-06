//
// Created by l1nkkk on 2021/8/9.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode206{
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr){
            pre =  head;
            return head;
        }
        ListNode* rtn = reverseList(head->next);
        pre->next = head;
        pre = head;
        head->next = nullptr;
        return rtn;
    }
private:
    ListNode* pre;
};

ListNode* Build(initializer_list<int> init){
    ListNode *head = nullptr;
    ListNode *re = nullptr;
    for(auto i : init){
        if(head == nullptr){
            head = new ListNode(i);
            re = head;
        }else{
            re->next = new ListNode(i);
            re = re->next;
        }
    }
    return head;
}

void test(){
    ListNode* head = Build({1,2,3});
    Solution s;
    auto res = s.reverseList(head);
    while(res){
        cout << res->val <<" ";
        res = res->next;
    }
}
}