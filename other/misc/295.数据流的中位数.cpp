//
// Created by l1nkkk on 2021/8/9.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
namespace leetcode295{
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        // 让两个优先队列平衡
        if(small.size() == 0){
            small.push(num);
            return;
        }
        if(small.size() == large.size()){
            if (num <= large.top()){
                small.push(num);
            }else{
                auto t = large.top();
                large.pop();
                small.push(t);
                large.push(num);
            }
        }else{
            if (num >= small.top()){
                large.push(num);
            }else{
                auto t = small.top();
                small.pop();
                large.push(t);
                small.push(num);
            }
        }
    }

    double findMedian() {
        if(small.size() > large.size()){
            return small.top();
        }else{
            return double(small.top()+large.top())/2.0;
        }
    }
private:
    priority_queue<int, vector<int>,greater<int>> large;  // 存最大的一半，每次弹出最小的
    priority_queue<int> small;//存最小的一半，每次弹出最大的
//    bool flag = true;//true 放small， false放large
};
void test(){
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    cout << m.findMedian() << endl;
    m.addNum(3);
    cout << m.findMedian() << endl;
}
}