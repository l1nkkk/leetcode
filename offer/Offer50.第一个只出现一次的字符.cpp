//
// Created by l1nkkk on 2022/4/10.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
using namespace std;

namespace offer50{
class Solution {
public:
    char firstUniqChar(string s) {
        // 字符 ： 第一次出现的 index
        unordered_map<char, int> record;

        // 符合结果的 index 集合
        set<int> resSet;

        for(int i = 0; i < s.size(); ++i){
            if(record.count(s[i]) == 0){
                resSet.insert(i);
                record[s[i]] = i;
            }else{
                if(!resSet.count(i))
                    resSet.erase(record[s[i]]);
            }
        }
        return resSet.empty()? ' ': s[*resSet.begin()];
    }
};

void test(){
    Solution s;
    cout << s.firstUniqChar("loveleetcode");
}

}