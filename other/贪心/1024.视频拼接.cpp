//
// Created by l1nkkk on 2022/3/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
namespace leetcode1024{
class Solution {
public:
    struct cmp{
        bool operator()(vector<int> &a, vector<int> &b){
            if( a[0] < b[0]){
                return true;
            }else if( a[0] == b[0]){
                return a[1] > b[1];
            }else{
                return false;
            }
        }
    };
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), cmp());
        for(auto a : clips){
            cout << a[0] << " " << a[1] << endl;
        }
        int curRight = 0;
        int res = 0;
        int nextRight = 0;
        int i = 0;
        while(i < clips.size() && clips[i][0] <= curRight){
            // 在第 res 个视频区间内，贪心选择下一个视频
            while(i <clips.size() &&  clips[i][0] <= curRight){
                nextRight = max(nextRight, clips[i][1]);
                ++i;
            }
            ++res;// 找到视频，更新结果
            curRight = nextRight;
            if(curRight >= time){
                return res;
            }
        }
        return -1;
    }
};
void test(){
//    vector<vector<int>> input{ {0,2 }, {4,6 }, {8,10 }, {1,9 }, {1,5 }, {5,9 } };
    vector<vector<int>> input{ {0,2 }, {1,6 }, {3,10 } };

    Solution s;
    cout<<s.videoStitching(input, 10);
}
}