//
// Created by l1nkkk on 2022/8/5.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace offer2_42{
class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        while(!que.empty() && que.front() < t-3000){
            que.pop();
        }
        que.push(t);
        return que.size();
    }

private:
    queue<int> que;
};

void test(){

}

}