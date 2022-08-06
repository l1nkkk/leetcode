//
// Created by l1nkkk on 2022/3/21.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer6{

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int n = 0;
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        dfs(res, head);
        return res;
    }
    void dfs(vector<int>& res, ListNode* head){
        if(head == NULL){
            res.reserve(n);// 避免频繁 re malloc
            return;
        }
        ++n;
        dfs(res,head->next);
        res.push_back(head->val);
    }
};
}