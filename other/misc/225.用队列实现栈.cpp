//
// Created by l1nkkk on 2021/8/30.
//

#include <queue>
#include <iostream>
using namespace std;

namespace leetcode225{
class MyStack {
public:
    queue<int> que;
    int topElem;
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        topElem = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int sz = que.size();
        for(int i = 0; i < sz-1; ++i){
            if(i == sz-2) topElem = que.front();
            que.push(que.front());
            que.pop();

        }
        int rnt = que.front();
        que.pop();
        return rnt;
    }

    /** Get the top element. */
    int top() {
        return topElem;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

void test(){
    MyStack st;
    st.push(1);
    st.push(2);
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
}
}