//
// Created by l1nkkk on 2022/3/27.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace offer35{

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* it = head;
        Node* res = nullptr;
        Node* resit = nullptr;
        // init and deal next
        while(it != nullptr){
            if(res == nullptr){
                res = new Node(it->val);
                resit = res;
            }else{
                resit->next = new Node(it->val);
                resit = resit->next;
            }
            record[it] = resit;
            it = it->next;
        }

        // 处理 rand
        it = head;
        resit = res;
        while(it != nullptr){
            if(it->random != nullptr){
                resit->random = record[it->random];
            }
            resit = resit->next;
            it = it->next;
        }
        return res;
    }

private:
    unordered_map<Node*,Node*> record;
};
}
