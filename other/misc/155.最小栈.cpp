//
// Created by l1nkkk on 2021/9/11.
//
#include <stack>
using namespace std;
namespace leetcode155{
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        if(stk.empty()){
            stk.push({val,val});
        }else{
            stk.push({val,min(val,stk.top().second)});
        }
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }

private:
    stack<pair<int, int>> stk;
};
}