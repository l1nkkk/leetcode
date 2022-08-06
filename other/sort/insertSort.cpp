//
// Created by l1nkkk on 2021/8/20.
//

#include <iostream>
#include <vector>
using namespace std;


namespace sortFunc{
class InsertSort{
public:
    void sort(vector<int>&nums){
        for(int i = 1; i < nums.size(); ++i){
            for(int j = i-1; j >= 0; --j){
                if(nums[j] < nums[j+1])
                    break;
                swap(nums[j+1],nums[j]);
            }
        }
    }
};

void testInsertSort(){
    InsertSort is;
    vector<int> input{4,1,5,9,2,6,5,6,1,8,0,7 };
//    vector<int> input{4,1,5 };

    is.sort(input);
    for(auto i : input){
        cout << i << " ";
    }
}
}
