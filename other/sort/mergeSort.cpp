//
// Created by l1nkkk on 2021/8/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace sortFunc{
class MergeSort{
public:
    vector<int> output;
    void sort(vector<int>& nums, int start, int end, vector<int>& output){
        if(start >= end)
            return;
        int mid = (start + end)/2;
        sort(nums, start, mid, output);
        sort(nums, mid+1, end, output);
        merge(nums, start, mid, mid+1, end, output);
    }

    void merge(vector<int>& nums, int lstart, int lend, int rstart, int rend, vector<int> &output){
        int pos = lstart;
        int start = lstart;
        while(lstart <= lend && rstart <= rend){
            if(nums[lstart] < nums[rstart]){
                output[pos++] = nums[lstart++];
            }else{
                output[pos++] = nums[rstart++];
            }
        }
        while(lstart <= lend){
            output[pos++] = nums[lstart++];
        }
        while(rstart <= rend){
            output[pos++] = nums[rstart++];
        }

        // 重要
        for(int i = start; i <= rend; ++i){
            nums[i] = output[i];
        }
    }
};

void testMergeSort(){
    MergeSort ms;
    vector<int> input{4,1,5,9,2,6,5,6,1,8,0,7 };
//    vector<int> input{4,1,5,9,2 };
    vector<int> ouput(input.size());
    ms.sort(input, 0, input.size()-1, ouput);
    for(auto i : ouput){
        cout << i << " ";
    }
}

}
