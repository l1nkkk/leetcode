//
// Created by l1nkkk on 2021/8/20.
//

#include <iostream>
#include <vector>
using namespace std;

namespace sortFunc{
class SelectSort{
public:
    void sort(vector<int> &nums){
        for(int i = 0; i < nums.size()-1; ++i){
            int maxIdx = 0;
            for(int j = 1; j < nums.size()-i;++j){
                if(nums[j]>nums[maxIdx])
                    maxIdx = j;
            }
            swap(nums[maxIdx], nums[nums.size()-i-1]);
        }
    }
};

void testSelectSort(){
    SelectSort ss;
    vector<int> input{4,1,5,9,2,6,5,6,1,8,0,7 };
//    vector<int> input{4,1,5 };

    ss.sort(input);
    for(auto i : input){
        cout << i << " ";
    }
}
}