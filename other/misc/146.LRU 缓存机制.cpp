//
// Created by l1nkkk on 2021/8/8.
//

#include <unordered_map>
#include <iostream>

using namespace std;

namespace leetcode146{
struct Node{
    Node(int akey, int aval){
        key = akey;
        val = aval;
    }
    int key;
    int val;
    Node *pre = nullptr,*next = nullptr;
};

class DoubleList{
public:
    int getSize(){
        return size;
    }
    Node* removeNode(Node* target){
        // 如果是head
        if(head == target){
            head = target->next;
        }else{
            target->pre->next = target->next;
        }

        if(tail == target){
            tail = target->pre;
        }else{
            target->next->pre = target->pre;
        }
        --size;
        return target;
    }

    Node* removeTail(){
        return removeNode(tail);
    }
    void insertToHead(Node* n){
        if(head == nullptr){
            head = n;
            tail = n;
        }else{
            head->pre = n;
            n->next = head;
            head = n;
        }
        ++size;
    }

private:
    int size = 0;
    Node *head = nullptr, *tail = nullptr;
};


class HashListEx{
public:
    int getSize(){return size;}
    bool exist(int key){ return index.count(key) != 0;}
    Node* get(int key){

        if(index.count(key) == 0) return nullptr;
        Node* rtn;
        rtn = index[key];
        return rtn;
    }
    void removeNode(Node* n){
        if(index.count(n->key) == 0)
            return;
        index.erase(n->key);
        dl.removeNode(n);
        --size;
    }
    void insertToHead(Node* n){
        index[n->key] = n;
        dl.insertToHead(n);
        ++size;
    }
    void removeTail(){
        auto rtn = dl.removeTail();
        index.erase(rtn->key);
        --size;
    }
private:
    unordered_map<int,Node*> index;
    DoubleList dl;
    int size = 0;
};


class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        len = 0;
    }

    int get(int key) {
        // 有的话就返回val，没返回-1
        // 内部需要修改时序了，假设链表尾为最长没有被使用的
        Node *node = hle.get(key);
        if(node == nullptr)return -1;
        hle.removeNode(node);
        hle.insertToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        // 有的话就进行更新，同时进行时序修改
        // 没有的话就进行插入，如果超过的容量，要删除最长时间没用的
        if(hle.exist(key)){
            Node* node = hle.get(key);
            node->val = value;
            // 删除后插入头部
            hle.removeNode(node);
            hle.insertToHead(node);
        } else{
            Node *node = new Node(key,value);
            hle.insertToHead(node);
            ++len;
            if(len > cap){
                hle.removeTail();
                --len;
            }
        }
    }

private:
    int cap;
    int len;
    HashListEx hle;
};

void test(){
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache->get(2) << endl;    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache->get(3) << endl;    // 返回 3
    cout << lRUCache->get(4) << endl;    // 返回 4


}

}