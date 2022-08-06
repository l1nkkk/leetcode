//
// Created by l1nkkk on 2022/3/16.
//

#include <iostream>
#include <vector>
using namespace std;

namespace leetcode303{
class NumArray {
public:
    NumArray(vector<int>& nums) {
        pres_.resize(nums.size()+1);
        pres_[0] = 0;
        for(int i = 0; i < pres_.size()-1; ++i){
            pres_[i+1] = nums[i] + pres_[i];
        }
    };

    int sumRange(int left, int right) {
        return pres_[right+1] - pres_[left];
    }

private:
    vector<int64_t> pres_;
};


void test(){
    vector<int> input{-2, 0, 3, -5, 2, -1};
    NumArray n(input);
    cout << n.sumRange(0, 2) << endl;
    cout << n.sumRange(2, 5) << endl;
    cout << n.sumRange(0, 5) << endl;
}
}