//
// Created by l1nkkk on 2021/8/4.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
namespace leetcode37{
class Solution {
public:
    set<char> cube[3][3];
    set<char> line[9];
    set<char> col[9];
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j]=='.')
                    continue;
                cube[i/3][j/3].insert(board[i][j]);
                line[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
            }
        }

        dfs(board,0,0);
    }

    bool dfs(vector<vector<char>>& board, int x, int y){
        if(x == 9 )
            return true;
        if(board[x][y] != '.'){
            if(y < 8)
                return dfs(board, x, y+1);
            else
                return dfs(board,x+1, 0);
        }

        for(int i = 1; i <=9; ++i){
            if(!check(x, y, i+'0'))
                continue;

            line[x].insert(i+'0');
            col[y].insert(i+'0');
            cube[x/3][y/3].insert(i+'0');
            board[x][y] = i+'0';
            if(y < 8){
                if(dfs(board, x, y+1))
                    return true;
            }else{
                auto t = dfs(board, x+1, 0);
                if(t){
                    return true;
                }
            }
            board[x][y] = '.';
            line[x].erase(i+'0');
            col[y].erase(i+'0');
            cube[x/3][y/3].erase(i+'0');
        }
        return false;

    }
    bool check(int x, int y, int val){
        if(line[x].find(val) != line[x].end())
            return false;

        if(col[y].find(val) != col[y].end())
            return false;

        if(cube[x/3][y/3].find(val) != cube[x/3][y/3].end())
            return false;
        return true;
    }
};

void test(){
    vector<vector<char>> m{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    Solution s;
    s.solveSudoku(m);
    for(auto &x:m){
        for(auto &y:x){
            cout << y << " ";
        }
        cout << endl;
    }

}

}