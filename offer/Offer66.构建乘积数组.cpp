//
// Created by l1nkkk on 2022/4/16.
//

#include <iostream>
#include <vector>
using namespace std;

namespace offer66{
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res(a.size(), 1);
        int temp = 1;
        // 下三角
        for(int i = 1; i < a.size(); ++i){
            res[i] *= a[i];
        }
        int t = 1;
        for(int i = a.size()+2; i >= 0; --i){
            res[i] *= a[i];
            t *= a[i];
        }
        return  res;
    }
};
}