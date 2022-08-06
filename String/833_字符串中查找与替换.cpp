//
// Created by l1nkkk on 4/3/21.
//
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;
namespace leetcode833{
class Solution {
    bool cmpIdx(const int a, const int b){
        return a < b;
    }

public:
    string findReplaceString(string S, vector<int> &indexes, vector<string> &sources, vector<string> &targets) {
        stringstream ss;
        map<int,pair<string,string>, less<int>> m;
        int pos = 0;

        // 初始化m
        for(int i = 0;i < indexes.size(); ++i){
            m[indexes[i]] = make_pair(sources[i],targets[i]);
        }


        int i = 0;
        auto it = m.begin();
        while (i < S.length()) {
            if (i == it->first) {
                // 比较下sources是否匹配
                if (it->second.first == S.substr(i, it->second.first.length())) {
                    // ss << targets[pos];
                    ss << it->second.second;
                    // i += sources[pos].length();
                    i += it->second.first.length();
                    ++it;
                    continue;
                }
            }
            if(it->first == i) ++it;
            ss << S[i];
            ++i;

        }
        return ss.str();
    }
};

void test(){
    Solution s;
    vector<int> v1 = {46,29,2,44,31,26,42,9,38,23,36,12,16,7,33,18};
    vector<string> v2 = {"rym","kv","nbzxu","vx","js","tp","tc","jta","zqm","ya","uz","avm","tz","wn","yv","ird"};
    vector<string> v3 = {"gfhc","uq","dntkw","wql","s","dmp","jqi","fp","hs","aqz","ix","jag","n","l","y","zww"};
    cout << s.findReplaceString("mhnbzxkwzxtaanmhtoirxheyanoplbvjrovzudznmetkkxrdmr",v1,v2, v3);
}

}

//"mhnbzxkwzxtaanmhtoirxhe yanoplbvjrovzudznmetkkxrdmr"
//"mhnbzxkwzxtaanmhtoirxheaqznoplbvjrovzudznmetkkxrdmr"
// "mhnbzxkwzxtaanmhtoirxheyanoplbvjrovzudznmetkkxrdmr"
//[46,29,2,44,31,26,42,9,38,23,36,12,16,7,33,18]
//["rym","kv","nbzxu","vx","js","tp","tc","jta","zqm","ya","uz","avm","tz","wn","yv","ird"]
//["gfhc","uq","dntkw","wql","s","dmp","jqi","fp","hs","aqz","ix","jag","n","l","y","zww"]