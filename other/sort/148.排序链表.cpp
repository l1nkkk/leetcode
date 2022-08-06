//
// Created by l1nkkk on 2021/8/24.
//
#include <iostream>
#include <vector>
using namespace std;

namespace leetcode148{
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
    // return {head, tail}
    pair<ListNode*,ListNode*> Merge(ListNode* l1, ListNode *l2){
        if(l1 == nullptr && l2 == nullptr)
            return {nullptr, nullptr};
        ListNode *head, *tail;
        head = new ListNode(0);
        tail = head;
        ListNode *it1, *it2;
        it1 = l1;
        it2 = l2;
        while(it1 != nullptr && it2 != nullptr){
            if(it1->val <= it2->val){
                tail->next = it1;
                it1 = it1->next;
            }else {
                tail->next = it2;
                it2 = it2->next;
            }
            tail = tail->next;
        }
        if(it1 != nullptr){
            tail->next = it1;
        }
        if(it2 != nullptr){
            tail->next = it2;
        }
        while(tail->next != nullptr){
            tail = tail->next;
        }
        return {head->next,tail};

    }
    ListNode* sortList(ListNode* head) {
        int partLen = 1;
        ListNode *it = head;
        ListNode* res = head;
        int len = 0;
        while(it != nullptr){
            ++len;
            it = it->next;
        }
        // 总的思路：分裂链表，之后归并
        // partLen部分都是排序好的一小段，从1开始。
        while(partLen < len){
            ListNode *next = res;
            ListNode *nextPre = new ListNode(0,res);
            // next为下一个处理的起点
            while(next) {
                ListNode *cur = next;
                ListNode *preCur = nullptr;
                ListNode *l1,*l2;

                // 寻找链表片段
                int i = 0;
                l1 = cur;
                while(cur != nullptr && i < partLen){
                    preCur = cur;
                    cur = cur->next;
                    ++i;
                }
                if(cur == nullptr){
                    nextPre->next = next;   // 注意，必须连接，不然就丢失了
                    break;
                }
                preCur->next = nullptr; //切断

                // 寻找另一链表片段
                i = 0;
                l2 = cur;
                while(cur != nullptr && i < partLen){
                    preCur = cur;
                    cur = cur->next;
                    ++i;
                }
                preCur->next = nullptr;

                // 归并
                auto rtn = Merge(l1,l2);

                // 与归并完的链表连接处理
                if(next == res) res = rtn.first;
                nextPre->next = rtn.first;
                nextPre = rtn.second;
                next = cur;
            }
            partLen*=2;
        }
        return res;
    }
};

void test(){
    auto input = Build({4,2,1,3});
    Solution s;
    auto res = s.sortList(input);
    cout << "test";
}
}


