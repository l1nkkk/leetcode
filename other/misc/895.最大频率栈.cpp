//
// Created by l1nkkk on 2021/8/9.
//

#include <stack>
#include <map>
#include <iostream>
using namespace std;

namespace leetcode895{
class FreqStack {
public:
    FreqStack() {

    }

    void push(int val) {
        ++valToFreq[val];
        freqToStack[valToFreq[val]].push(val);
    }

    int pop() {
        auto it = freqToStack.rbegin();
        auto rtn = it->second.top();
        it->second.pop();
        --valToFreq[rtn];
        if(it->second.size() == 0){
            freqToStack.erase(it->first);
        }
        return rtn;
    }
private:
    map<int,int> valToFreq;
    map<int,stack<int>> freqToStack;
};

void test(){
    FreqStack fs;
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);
    cout << fs.pop();
    cout << fs.pop();
    cout << fs.pop();
    cout << fs.pop();
}
void test1(){
    FreqStack fs;
    fs.push(1);
    fs.push(1);
    fs.push(1);
    fs.push(2);
    cout << fs.pop();
    cout << fs.pop();
    fs.push(2);
    fs.push(2);
    fs.push(1);
    cout << fs.pop();
    cout << fs.pop();
    cout << fs.pop();
}
}
