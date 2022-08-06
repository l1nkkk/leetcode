//
// Created by l1nkkk on 2021/8/1.
//
#include <vector>
#include <iostream>
using namespace std;
namespace unionFind{
class UF{
public:
    int count; // 连通分量数量
    // 记录x节点指向的父亲（相当于指针）
    vector<int> parent;
    // 记录x节点为根的树的大小
    vector<int> size;
public:
    UF(int n){
        count = n;
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }

    void Union(int p, int q){
        int proot = Find(p);
        int qroot = Find(q);
        if(proot == qroot)
            return;
        // 将小树接到大树那
        if(size[proot] > size[qroot]){
            parent[qroot] = proot;
            size[proot] += size[qroot];
        }else{
            parent[proot] = qroot;
            size[qroot] += size[proot];
        }
        --count;
    }
    bool IsConnect(int p, int q){
        int proot = Find(p);
        int qroot = Find(q);
        if(proot == qroot)
            return true;
        return false;
    }
    int Find(int x){
        // 压缩树，顺便减少该节点这一路的高度
        while(parent[x] != x){
            size[parent[x]] -= size[x];
            size[parent[parent[x]]] += size[x];
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    int Count(){
        return count;
    };

};

void test(){
    UF uf(10);
    uf.Union(1,2);
    uf.Union(3,4);
    uf.Union(2,3);
    uf.Union(6,7);
    uf.Union(9,8);
    uf.Union(6,8);
    uf.Union(3,7);
    cout << uf.Count();


}
}