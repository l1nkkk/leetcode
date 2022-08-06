//
// Created by l1nkkk on 2022/3/28.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


namespace offer38{
class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> res;
        res.push_back(s);
        // 全排列
        /// 1.从右到左找到第一个递增的，如果找不到就退出
        int i = s.length()-2, ii = s.length()-1;
        while(i >= 0){
            if(s[i] >= s[ii]) {// 注意：是>=
                --i;--ii;
                continue;
            }
            else{
                /// 2. 从右到左找到 比s[i] 大的第一个数，记为j
                int j = s.length()-1;
                // 注意：是<=,找到第一个大于的，而不是大于等于
                while(s[j] <= s[i]) {
                    --j;
                    continue;
                };
                /// 3. swap & reverse
                swap(s[i],s[j]);
                reverse(s.begin()+ii,s.end());
                res.push_back(s);
                i = s.length()-2;
                ii = s.length()-1;
            }
        }
        return res;
    }
};
void test(){
    Solution s;
    auto res = s.permutation("aab");
    for(auto a : res){
        cout << a << " ";
    }
}
}