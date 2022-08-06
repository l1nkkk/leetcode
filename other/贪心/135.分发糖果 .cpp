//
// Created by l1nkkk on 2022/3/12.
//
#include <iostream>
#include <vector>
using namespace std;
namespace leetcode135{
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left,right;
        int res = 0;
        left.resize(ratings.size());
        right.resize(ratings.size());

        int i=1;
        left[0] = 1;
        for(; i < ratings.size(); ++i){
            if(ratings[i-1] < ratings[i]){
                left[i] = left[i-1]+1;
            }else{
                // ratings[i-1] >= ratings[i]
                left[i] = 1;
            }
        }

        i = ratings.size()-2;
        right[ratings.size()-1] = 1;
        for(; i >=0 ; --i){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1]+1;
            }else{
                // ratings[i-1] >= ratings[i]
                right[i] = 1;
            }
        }

        // 归并，取最大
        for(int i = 0; i < ratings.size(); ++i){
            res += max(left[i], right[i]);
        }
        return res;

    }
};

void test(){
//    vector<int> input{1,2,2};
    vector<int> input{1,3,2,2,1};
    Solution s;
    cout << s.candy(input);
}
}