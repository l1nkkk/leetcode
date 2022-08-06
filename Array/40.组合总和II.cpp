//
// Created by l1nkkk on 2022/3/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
namespace leetcode40{
class Solution {
public:

vector<vector<int>> res;
vector<int> record;

void show(vector<int>::iterator it1, vector<int>::iterator it2){
    while(it1 != it2){
        cout << *it1++ << " ";
    }
    cout << endl;
}

void dfs(vector<int>& candidates, int target, int base){
    if(target == 0){
        res.push_back(record);
        cout << "符合条件的结果: ";
        show(record.begin(),record.end());
        return;
    }
    // 剪枝
    if(base >= candidates.size() || candidates[base] > target)
        return;
    int it = base;
    while(it < candidates.size()){
        record.push_back(candidates[it]);
//        cout << "进入递归：";
//        show(record.begin(),record.end());
        dfs(candidates, target-candidates[it],it+1);
        record.pop_back();
//        cout << "退出递归：";
//        show(record.begin(),record.end());
        while(it+1 < candidates.size() &&candidates[it+1] == candidates[it]){
            ++it;
        }
        ++it;
    }

}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0);
    return res;
}
};


void test(){
//    vector<int> input{10,1,2,7,6,1,5};
    vector<int> input{2,5,2,1,2};
    Solution s;
    s.combinationSum2(input, 5);
}

}