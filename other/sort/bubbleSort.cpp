//
// Created by l1nkkk on 2021/8/20.
//
#include <iostream>
#include <vector>
using namespace std;


namespace sortFunc{
class BubbleSort{
public:
    void sort(vector<int>& nums){
        for(int i = 0; i < nums.size()-1; ++i){
            for(int j = 0; j < nums.size()-i-1; ++j){
                if(nums[j] > nums[j+1]){
                    nums[j] ^= nums[j+1];
                    nums[j+1] ^= nums[j];
                    nums[j] ^= nums[j+1];
                }
            }
        }
    }
};
void testBubbleSort(){
    BubbleSort bs;
    vector<int> input{4,1,5,9,2,6,5,6,1,8,0,7 };
//    vector<int> input{4,1,5 };

    bs.sort(input);
    for(auto i : input){
        cout << i << " ";
    }
}

}
