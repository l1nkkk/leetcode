//
// Created by l1nkkk on 2021/8/9.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
namespace leetcode460{
struct Node{
    Node(int akey, int aval){
        key = akey;
        val = aval;
        freq = 1;
        pre = nullptr;
        next = nullptr;
    }
    int key,val;
    int freq;
    Node *pre,*next;
};
class DoubleList{
public:
    void insertTohead(Node* node){
        if(head == nullptr){
            head = node;
            tail = node;
        }else{
            head->pre = node;
            node->next = head;
            head = node;
        }
    }
    Node* removeNode(Node* n){
        if(n == head){
            head = n->next;
        }else{
            n->pre->next = n->next;
        }
        if(n == tail){
            tail = n->pre;
        }else{
            n->next->pre = n->pre;
        }
        return n;
    }

    Node* removeTail(){
        return removeNode(tail);
    }
private:
    Node *head,*tail;
};

class hashList{
public:
    void addNode(Node* node){
        dl.insertTohead(node);
        index[node->key] = node;
    }
    Node* removeTail(){
        auto rtn = dl.removeTail();
        index.erase(rtn->key);
        return rtn;
    }
    void removeNode(Node* node){
        dl.removeNode(node);
        index.erase(node->key);

    }
    int getSize(){
        return index.size();
    }

private:
    DoubleList dl;
    map<int, Node*> index;
};

class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        len = 0;
    }

    int get(int key) {
        // 不存在返回-1
        if(keyToNode.count(key) == 0){
            return -1;
        }
        // 存在就返回，并且freq+1
        Node* rtn;
        rtn = keyToNode[key];
        update(key);
        return rtn->val;
    }

    void put(int key, int value) {
        if(cap == 0) return;
        // 如果已经存在了，则修改val和freq
        if(keyToNode.count(key) != 0){
            keyToNode[key]->val = value;
            update(key);
        }else{
            ++len;
            // 如果不存在，则添加
            keyToNode[key] = new Node(key,value);
            if(len > cap){
                --len;
                auto it = freqToSet.begin();
                auto rtn = it->second.removeTail();
                if(it->second.getSize() == 0)
                    freqToSet.erase(rtn->freq);
                keyToNode.erase(rtn->key);

            }
            freqToSet[1].addNode(keyToNode[key]);
        }
    }
    void update(int key){
        Node* rtn = keyToNode[key];
        //      删除原来所在
        freqToSet[rtn->freq].removeNode(rtn);
        if(freqToSet[rtn->freq].getSize() == 0)
            freqToSet.erase(rtn->freq);
        ++rtn->freq;
        //      加入到新的freq集合
        freqToSet[rtn->freq].addNode(rtn);
    }
private:
    map<int, Node*> keyToNode;
    map<int, hashList> freqToSet;
    int len;
    int cap;
};

void test(){
    LFUCache *lFUCache = new LFUCache(2);
    lFUCache->put(1, 1);   // cache=[1,_], cnt(1)=1
    lFUCache->put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lFUCache->get(1)<< endl;      // 返回 1
    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lFUCache->put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
    // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lFUCache->get(2)<< endl;      // 返回 -1（未找到）
    cout << lFUCache->get(3)<< endl;      // 返回 3
    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lFUCache->put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
    // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lFUCache->get(1)<< endl;      // 返回 -1（未找到）
    cout << lFUCache->get(3)<< endl;      // 返回 3
    // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lFUCache->get(4)<< endl;      // 返回 4

}

void test1(){
    LFUCache *lFUCache = new LFUCache(2);
    lFUCache->put(3, 1);
    lFUCache->put(2, 1);
    lFUCache->put(2, 2);
    lFUCache->put(4, 4);
    cout << lFUCache->get(2)<< endl;      // 返回 1
}

void test2(){
    LFUCache *lFUCache = new LFUCache(0);
    lFUCache->put(0, 0);
    cout << lFUCache->get(0)<< endl;      // 返回 1
}

}
