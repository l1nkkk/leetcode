//
// Created by l1nkkk on 2022/3/22.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer11{
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int lo = 0;
        int hi = numbers.size()-1;
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(numbers[mid] < numbers[hi]){
                hi = mid;
            }else if(numbers[mid] < numbers[hi]){
                // mid 不可能是最小值
                lo = mid+1;
            }else{
                hi--; // 难点
            }
        }
        return numbers[lo];
    }
};
void test(){
    Solution s;
    vector<int> input{};
    cout <<s.minArray(input);
}

}