//
// Created by l1nkkk on 2021/10/5.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace leetcode128{

class UF{
public:
    UF(int n):count(n), parent(n), treeSize(n,1), maxts(1){
        for(auto i = 0; i < n; ++i){
            parent[i] = i;
        }
    }

    void Union(int x, int y){
        auto lroot = find(x);
        auto rroot = find(y);

        if(lroot == rroot) return;

        if(treeSize[lroot] > treeSize[rroot]){
            parent[rroot] = lroot;
            treeSize[lroot] += treeSize[rroot];
            maxts = max(maxts, treeSize[lroot]);
        }else if(treeSize[lroot] <= treeSize[rroot]){
            parent[lroot] = rroot;
            treeSize[rroot] += treeSize[lroot];
            maxts = max(maxts, treeSize[rroot]);
        }
    }

    bool Connected(int x, int y){
        auto lroot = find(x);
        auto rroot = find(y);
        if(lroot == rroot) true;
        return false;
    }
    int getMaxTreeSize(){
        return maxts;
    }


private:
    // 找x的根
    int find(int x){
        while(parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    vector<int> parent;
    vector<int> treeSize;
    vector<int> count;
    int maxts;
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int pos = 0;
        UF uf(nums.size());
        for(auto &n : nums){
            if(record.count(n))
                continue;
            record[n] = pos;
            if(record.count(n-1))
                uf.Union(record[n-1], pos);
            if(record.count(n+1))
                uf.Union(record[n+1],pos);
            ++pos;
        }
        return uf.getMaxTreeSize();
    }

private:
    // 值-----并查集节点
    unordered_map<int,int> record;
};


void test(){
//    vector<int> input{100,4,200,1,3,2};
    vector<int> input{0,3,7,2,5,8,4,6,0,1};
    Solution s;
    cout << s.longestConsecutive(input);
}

}

