//
// Created by l1nkkk on 2021/7/24.
//

#include <vector>
using namespace std;
namespace leetcode344{
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left,right;
        left = 0;
        right = s.size()-1;
        while(left < right){
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];
            ++left;
            --right;
        }
    }
};
}