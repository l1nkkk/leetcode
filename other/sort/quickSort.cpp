//
// Created by l1nkkk on 2021/8/20.
//

#include <vector>
#include <iostream>
using namespace std;

namespace sortFunc{
class QuickSort{
public:
    int partition(vector<int>& nums, int start, int end){
        int lo = start;
        int hi = end;
        int t = nums[lo];
        while(lo < hi){
            while(lo < hi && nums[hi] >= t){
                --hi;
            }
            if(lo >= hi)break;
            nums[lo++] = nums[hi];

            while(lo < hi && nums[lo] < t){
                ++lo;
            }
            if(lo >= hi) break;
            nums[hi--] = nums[lo];
        }
        nums[lo] = t;
        return lo;
    }
    void sort(vector<int>& nums, int start, int end){
        if(start+1 >= end)
            return;
        int p = partition(nums, start ,end);
        sort(nums,start,p-1);
        sort(nums,p+1, end);
    }
};

void testQuickSort(){
    QuickSort qs;
    vector<int> input{4,1,5,9,2,6,5,6,1,8,0,7 };
    qs.sort(input, 0, input.size()-1);
    for(auto i : input){
        cout << i << " ";
    }

}
}
