//
// Created by l1nkkk on 2022/3/9.
//

#include <iostream>
#include <string>
#include <stack>
#include <assert.h>
using namespace std;

namespace leetcode208{
template<typename V, uint8_t LIMIT, uint8_t OFFSET, V VNULL_>
class TrieMap{
private:
    static constexpr uint8_t offset_ = OFFSET;
    static constexpr uint8_t limit_ = LIMIT;
    static constexpr V VNULL = VNULL_;

    template<typename T>
    class TrieNode{
    public:
        V val_ = VNULL_;
        TrieNode* child_[limit_]{nullptr};

        bool hasChild(){
            for(int i = 0; i < limit_; i++){
                if(child_[i])return true;
            }
            return false;
        }
    };
    TrieNode<V>* root_;

public:
    TrieMap():root_(new TrieNode<V>){}
    void put(string k, V v);
    V get(string k);
    bool remove(string k);
    bool startWith(string k);
};

template<typename V, uint8_t LIMIT, uint8_t OFFSET, V VNULL_>
void TrieMap<V, LIMIT, OFFSET, VNULL_>::put(string k, V v) {
    auto cur = root_;
    for(auto it : k){
        if(cur->child_[it - offset_]){
            cur = cur->child_[it - offset_];
        }else{
            cur->child_[it - offset_] = new TrieNode<V>;
            cur = cur->child_[it - offset_];
        }
    }
    cur->val_ = v;
}

template<typename V, uint8_t LIMIT, uint8_t OFFSET, V VNULL_>
V TrieMap<V, LIMIT, OFFSET, VNULL_>::get(string k) {
    auto cur = root_;
    for(auto it : k){
        cur = cur->child_[it - offset_];
        if(!cur){
            return VNULL;
        }
    }
    // 不需要判断val是否为VNULL
    return cur->val_;
}

// l1nkkk: 未测试，因为该题目没有涉及
template<typename V, uint8_t LIMIT, uint8_t OFFSET, V VNULL_>
bool TrieMap<V, LIMIT, OFFSET, VNULL_>::remove(string k){
    // 注： 删除的时候需要把没有孩子、没有val的node给删了
    stack<pair<uint8_t ,TrieNode<V>*>> st;
    auto cur = root_;

    // 1. 遍历 k 路径，并保存路径
    for(auto it : k){
        if(!cur->child_[it - offset_]){
            // 不存在 k 这样的路径
            return false;
        }else{
            cur = cur->child_[it - offset_];
            st.push(make_pair(it - offset_, cur));
        }
    }

    // 执行到这，说明有该路径
    // 2. 判断是否有值，如果有值，则删除
    if(cur.val_ == VNULL)
        return false;
    else
        cur.val_ = VNULL;
ROUTE:
    // 3. 判断当前节点是否有child，如果有孩子，不需要删除该node
    if(cur.hasChild())
        return true;

    // 4. 如果没有孩子，需要递归删除
    st.top().second->child_[st.top().first] = nullptr;
    if(st.empty())
        return true;
    else{
        cur = st.top();
        st.pop();
        goto ROUTE;
    }

    assert(false);
}

template<typename V, uint8_t LIMIT, uint8_t OFFSET, V VNULL_>
bool TrieMap<V, LIMIT, OFFSET, VNULL_>::startWith(string k) {
    auto cur = root_;
    for(auto it : k){
        cur = cur->child_[it - offset_];
        if(!cur){
            return false;
        }
    }
    return true;
}

class Trie {
public:
    Trie() {
    }

    void insert(string word) {
        tm_.put(word,true);
    }

    bool search(string word) {
        return tm_.get(word);
    }

    bool startsWith(string prefix) {
        return tm_.startWith(prefix);
    }

private:
    TrieMap<bool, 26, 97, false> tm_;
};

void test(){
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // 返回 True
    cout << trie->search("app") << endl;     // 返回 False
    cout << trie->startsWith("app") << endl; // 返回 True
    trie->insert("app");
    cout << trie->search("app") << endl;     // 返回 True


}

}