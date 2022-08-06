//
// Created by l1nkkk on 2021/9/12.
//

#include <iostream>
#include <queue>
using namespace std;

namespace offer40{
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == 0 || arr.empty())return {};
        priority_queue<int> pque;
        for(auto &a: arr){
            if(pque.size() < k){
                pque.push(a);
            }else if(a < pque.top() && pque.size() == k){
                pque.pop();
                pque.push(a);
            }
        }
        vector<int> res;
        while(!pque.empty()){
            res.push_back(pque.top());
            pque.pop();
        }
        return res;
    }
};
void test(){
    Solution s;
    vector<int> input{3,2,1};
    auto res = s.getLeastNumbers(input,2);
    for(auto r : res){
        cout << r << " ";
    }

}
}