//
// Created by l1nkkk on 2021/8/30.
//

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st1,st2;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto rtn = peek();
        st2.pop();
        return rtn;
    }

    /** Get the front element. */
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};
