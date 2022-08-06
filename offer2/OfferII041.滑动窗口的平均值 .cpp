//
// Created by l1nkkk on 2022/8/5.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace offer2_41{
    class MovingAverage {
    public:
        MovingAverage(int size) {
            this->size = size;
            this->sum = 0.0;
        }

        double next(int val) {
            if (qu.size() == size) {
                sum -= qu.front();
                qu.pop();
            }
            qu.emplace(val);
            sum += val;
            return sum / qu.size();
        }
    private:
        int size;
        double sum;
        queue<int> qu;
    };

}
