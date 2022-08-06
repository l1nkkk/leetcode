//
// Created by l1nkkk on 2022/3/22.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer13{
class Solution {
public:
    int res = 0;
    int dist[2][2]{{0,1},{1,0}};

    int sum(int m){
        int s=0;
        while(m){
            s += (m%10);
            m/=10;
        }
        return s;
    }
    bool check(int x, int y ,int k){return sum(x)+sum(y) <= k;}

    void dfs(vector<vector<bool>>& record, int x, int y, int k){
        if(!check(x,y,k)) return;
        ++res;
        record[x][y] = true;
        cout << x << " " << y << endl;
        for(int i = 0; i < 2; ++i){
            auto nx = x+dist[i][0];
            auto ny = y+dist[i][1];
            if(nx >= 0 && nx < record.size() && ny >= 0 && ny < record[0].size() && !record[nx][ny])
                dfs(record,nx,ny,k);
        }
        return ;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> record(m,vector<bool>(n, false));
        dfs(record, 0,0,k);
        return res;
    }
};

void test(){
    Solution s;
    cout << s.movingCount(38,1,9);
}

}