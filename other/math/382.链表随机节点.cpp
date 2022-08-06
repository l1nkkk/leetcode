//
// Created by l1nkkk on 2021/8/7.
//

#include <iostream>
#include <random>
using namespace std;

namespace leetcode382{
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head;
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *t = head;
        int res;
        int i = 1;
        while (t!= nullptr){
            // 注：表示1/i的概率，1/i的概率会选中当前的值
            if(rand()%i == 0){
                res = t->val;
            }
            t = t->next;
            ++i;
        }
        return res;
    }
};
void test(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution s(head);
    cout <<s.getRandom() << endl;
    cout << s.getRandom()<< endl;
    cout << s.getRandom()<< endl;


}

}