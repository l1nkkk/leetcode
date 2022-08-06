//
// Created by l1nkkk on 2021/8/11.
//

#include <iostream>
#include <string>
using namespace std;

namespace leetcode1541{
class Solution {
public:
    int minInsertions(string s) {
        int need = 0;
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                if(need % 2 == 1){
                    ++res;
                    --need;
                }
                need+=2;
            }
            else if(s[i] == ')'){
                --need;
                if(need == -1){
                    ++res;
                    need = 1;
                }
            }
        }
        res += need;
        return res;
    }
};
void test(){
    Solution s;
    cout << s.minInsertions("(()))(()))()())))");
}
}