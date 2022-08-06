//
// Created by l1nkkk on 2021/8/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

namespace leetcode23{
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

struct cmp
{
    bool operator()(pair<ListNode *,int> a, pair<ListNode *,int> b)
    {
        if(a.first->val > b.first->val) return true;
        return false;
    }
};



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<ListNode *, int>, std::vector<pair<ListNode *,int>>, cmp> pq;
        ListNode *res = nullptr;
        ListNode *it = nullptr;
        // init
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] == nullptr) continue;
            pq.push(make_pair(lists[i],i));
            lists[i] = lists[i]->next;
        }

        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();

            // 更新
            if(lists[t.second]){
                pq.push(make_pair(lists[t.second],t.second));
                lists[t.second] = lists[t.second]->next;
            }

            // 加入结果
            if(res == nullptr){
                res = t.first;
                it = t.first;
            }else{
                it->next = t.first;
                it = it->next;
            }
        }
        return res;
    }
};


void test(){
    auto t1 = Build({1,4,5});
    auto t2 = Build({1,3,4});
    auto t3 = Build({2,6});
    Solution s;
    vector<ListNode*> input{t1,t2,t3};
    auto res = s.mergeKLists(input);
    cout << "test";
}
}