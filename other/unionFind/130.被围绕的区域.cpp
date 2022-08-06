//
// Created by l1nkkk on 2021/8/1.
//
#include <vector>
#include <iostream>
using namespace std;

namespace leetcode130{
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

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        UF uf(board.size()*board[0].size()+1);

        const int sizeX = board.size();
        const int sizeY = board[0].size();
        const int FLAG = sizeX*sizeY;
        // 上下边界
        for(int i = 0; i < sizeY;++i){
            if(board[0][i] == 'O')
                uf.Union(FLAG, i);
            if(board[sizeX-1][i] == 'O')
                uf.Union(FLAG, (sizeX-1)*sizeY+i);
        }
        // 左右边界
        for(int i = 0; i < sizeX;++i){
            if(board[i][0] == 'O')
                uf.Union(FLAG, i*sizeY);
            if(board[i][sizeY-1] == 'O')
                uf.Union(FLAG, (sizeY-1)+sizeY*i);
        }
        // 上右下左
        int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        for(int i = 1; i < sizeX-1; ++i){
            for(int j = 1; j <sizeY-1; ++j){
                if(board[i][j] == 'O')
                    for(int k = 0; k < 4; ++k){
                        if(board[i+d[k][0]][j+d[k][1]] == 'O')
                            uf.Union(i*sizeY+j, (i+d[k][0])*sizeY + j + d[k][1]);
                    }
            }
        }

        for(int i = 1; i < sizeX-1; ++i) {
            for (int j = 1; j < sizeY - 1; ++j) {
                if(board[i][j] == 'O' &&!uf.IsConnect(i*sizeY+j, FLAG)){
                    board[i][j] = 'X';
                }
            }
        }

    }
};

void test(){
    vector<vector<char>> input{{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'}};
    Solution s;
    s.solve(input);
    cout <<"test";
}

}