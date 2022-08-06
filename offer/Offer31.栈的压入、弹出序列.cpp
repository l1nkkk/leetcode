//
// Created by l1nkkk on 2022/3/27.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
namespace offer31{
class Solution {
public:
    stack<int> st;
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int lo = 0;
        for(int i = 0;i < pushed.size(); ++i){
            st.push(pushed[i]);
            while(st.empty() && st.top() == popped[lo]){
                st.pop();
                ++lo;
            }
        }
        if(lo != popped.size()) return false;
        return true;
    }
};

void test(){
    Solution s;
    {
        // false
        vector<int> input1{1,0,2};
        vector<int> input2{2,1,0};
        s.validateStackSequences(input1,input2);
    }
    {
        // false
        vector<int> input1{1,2,3,4,5};
        vector<int> input2{4,5,3,2,1,};
        s.validateStackSequences(input1,input2);
    }
}
};