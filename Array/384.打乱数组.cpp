//
// Created by l1nkkk on 2022/3/14.
//

#include <iostream>
#include <random>
using namespace std;

namespace leetcode384{
class Solution {
public:
    Solution(vector<int>& nums):ori_(nums), nums_(nums){
        srand(time(nullptr));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nums_ = ori_;
        return nums_;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = 0; i < nums_.size(); ++i){
            auto r = randint(i,nums_.size());
            swap(nums_[i], nums_[r]);
        }
        return nums_;
    }

private:
    // [i, j)
    int randint(int i,int j){
        return rand()%(j-i)+i;
    }
    vector<int> nums_;
    vector<int> ori_;
};
}
