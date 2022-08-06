//
// Created by l1nkkk on 2021/11/12.
//

#include <iostream>
#include <vector>

using namespace std;

namespace leetcode9{
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        vector<int> record;
        while(x){
            record.push_back(x%10);
            x /= 10;
        }

        int i,j;
        for(i = 0, j = record.size()-1; i < j; ++i, --j){
            if(record[i] != record[j])
                break;
        }
        if(i >= j) return true;
        return false;
    }
};

void test(){
    Solution s;
    cout << s.isPalindrome(11);
}
}