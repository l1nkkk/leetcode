//
// Created by l1nkkk on 4/6/21.
//

#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <functional>
#include <deque>
using namespace std;


namespace leetcode227{
class Solution {
public:
    int calculate(string s) {
        init_m();
        init_mopt();
        int64_t temp = 0;
        int64_t i = 0;
        while(i < s.length()){
            // 如果是数字
            if(isdigit(s[i]) != 0) {
                while (isdigit(s[i]) != 0) {
                    temp = temp * 10 + s[i] - '0';
                    ++i;
                }
                stnum.push(temp);
                temp = 0;
                continue;
            }
            else if(m.find(s[i]) != m.end()){
                // 比较优先级
                while(!stopt.empty() && (m[stopt.top()] >= m[s[i]])){
                    // 计算前面的运算符
                    int64_t n1 = stnum.top();
                    stnum.pop();
                    int64_t n2 = stnum.top();
                    stnum.pop();
                    stnum.push(mopt[stopt.top()](n2,n1));
                    stopt.pop();
                }
                stopt.push(s[i]);
            }
            else if(s[i] == '(')
                stopt.push('(');
            else if(s[i] == ')'){
                // 计算
                while(stopt.top() == '('){
                    int64_t n1 = stnum.top();
                    stnum.pop();
                    int64_t n2 = stnum.top();
                    stnum.pop();
                    stnum.push(mopt[stopt.top()](n2,n1));

                    stopt.pop();
                }
            }
            ++i;
        }
        // 处理未完成的
        while(!stopt.empty()){
            int64_t n1 = stnum.top();
            stnum.pop();
            int64_t n2 = stnum.top();
            stnum.pop();
            stnum.push(mopt[stopt.top()](n2,n1));
            stopt.pop();
        }
        return stnum.top();
    }

private:
    map<char, int64_t> m;
    map<char, function<int64_t(int64_t,int64_t)> > mopt;
    stack<int64_t> stnum;
    stack<char> stopt;
    void init_m(){
        m['('] = 0;
        m['+'] = 1;
        m['-'] = 1;
        m['*'] = 2;
        m['/'] = 2;
    }
    void init_mopt(){
        mopt['+'] = [](int64_t a, int64_t b) ->int64_t { return a+b;};
        mopt['-'] = [](int64_t a, int64_t b) ->int64_t { return a-b;};
        mopt['*'] = [](int64_t a, int64_t b) ->int64_t { return a*b;};
        mopt['/'] = [](int64_t a, int64_t b) ->int64_t { return a/b;};
    }
};
void test(){
    Solution s;
    cout <<  s.calculate("\"1*2-3/4+5*6-7*8+9/10\"") << endl;
}

}