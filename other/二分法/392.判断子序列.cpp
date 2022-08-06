//
// Created by l1nkkk on 2021/7/9.
//
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

namespace leetcode392 {
class Solution {
public:
    // 双指针法，对于只匹配一次比较有优势
    bool isSubsequence(string s, string t) {
        int si, ti;
        ti = 0;
        for (si = 0; si < s.size(); ++si){
            while(  ti < t.size() && t[ti] != s[si]){
                ++ti;
            }
            if( ti == t.size()) return false;
            ++ti;
        }
        return true;
    }
};

class Solution1 {
public:
    // 双指针法，对于只匹配一次比较有优势
    bool isSubsequence(string s, string t) {
        /**生成map*/
        map<char, vector<int>> mt;
        // o(n)
        for(int i = 0; i < t.size(); ++i){
            if(mt.find(t[i]) == mt.end())
                mt[t[i]] = {i};
            else
                mt[t[i]].push_back(i);
        }

        // 二分法
        // 当 target 不存在时，得到的索引恰好是比 val 大的最小元素索引
        int target;
        for(int i = 0; i < s.size(); ++i){
            if(target >= t.size()) return false;
            int left, right, mid;
            vector<int>& nums = mt[s[i]];
            left = 0;
            right = nums.size();
            target = 0;
            while(left < right){
                mid = left + (right - left)/2;
                if(nums[mid] < target){
                    left = mid+1;
                } else if (nums[mid] > target){
                    right = mid;
                } else if (nums[mid] == target){
                    right = mid;
                }
            }
            if(left == nums.size() ) return false;
            else target = nums[left]+1;
        }
        return true;
    }
};
void test(){
    Solution1 s;
    cout << s.isSubsequence("abc","ahbgdc");
}

}