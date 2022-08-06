//
// Created by l1nkkk on 3/29/21.
//
#include <string>
#include <iostream>

using namespace std;


namespace leetcode165{
class Solution {
public:
    int compareVersion(string version1, string version2) {
        string sub1,sub2;
        string vs1 = version1,vs2 = version2;
        // 先比较下标0主版本号,一级一级比下去
        while(!vs1.empty() && !vs2.empty() ){
            sub1 = vs1.substr(0, vs1.find('.'));
            sub2 = vs2.substr(0, vs2.find('.'));
            // 加0
            if(sub1.length() < sub2.length()){
                sub1.insert(0,sub2.length()-sub1.length(),'0');
            }
            if(sub1.length() > sub2.length()){
                sub2.insert(0,sub1.length()-sub2.length(),'0');
            }
            if(sub1 > sub2)
                return 1;
            else if(sub1 < sub2)
                return -1;

            // else
            // 更新下一轮
            if(vs1.find('.') != vs1.npos)
                vs1 = vs1.substr(vs1.find('.')+1);
            else
                vs1 = "";

            if( vs2.find('.') != vs2.npos)
                vs2 = vs2.substr(vs2.find('.')+1);
            else
                vs2 = "";


        }

        // 退出循环，判断退出状态，是否已经比出结果，是否已经
        // 如果vs1先为空
        if(vs1.empty() && vs2.find_first_not_of("0.") != vs2.npos)
            return -1;
        else if(vs2.empty() && vs1.find_first_not_of("0.") != vs1.npos)
            return 1;

        return 0;
    }
};

void test(){
    Solution s;
    cout << s.compareVersion("1.01","1.001");
}
}