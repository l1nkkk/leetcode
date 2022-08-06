//
// Created by l1nkkk on 2021/7/23.
//

#include <list>
using namespace std;
namespace leetcode25{

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto size = getSize(head);
        int i = 0;
        while(size >= k){
            head = reverseBetween(head, i*k, (i+1)*k);
            ++i;
            size -= k;
        }

        return head;
    }

    ListNode* reverseBetween(ListNode*head, int lo, int hi){
        if(lo == 0){
            return reverserPre(head, hi);
        }
        head->next = reverseBetween(head->next, lo-1, hi-1);
        return head;
    }
    ListNode* successor = nullptr;
    ListNode* reverserPre(ListNode* head, int n){
        // base case
        if( n == 1 ){
            successor = head->next;
            return head;
        }
        ListNode* last = reverserPre(head->next, n-1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

    int getSize(ListNode* head){
        int rtn = 0;
        while(head != nullptr){
            ++rtn;
            head = head->next;
        }
        return rtn;
    }

};
void test(){
    auto lt = Build({1,2,3,4,5});
    Solution s;
    s.reverseKGroup(lt,2);
}

}