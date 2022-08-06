//
// Created by l1nkkk on 2022/4/28.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace testyh{
void test(){
    int n;
    // 实际值，应该的处于的位置
    vector<int> firstInput;
    vector<int> secInput;
    unordered_map<int,int> record;
    //
    cin >> n;

    for(int i = 0; i < n; ++i){
        int t;
        cin >> t;
        record[t] = i;
        firstInput.push_back(t);
    }
    for(int i = 0; i < n; ++i){
        int t;
        cin >> t;
        // 把 t 替换成 i,需要找到t在哪个位置
        firstInput[record[t]] = i;
    }
    // 进行排序，选择最小的到前面
    int res = 0;
    for(int i = 0; i < n-1; ++i){
        for(int j = i; j < n; ++j){
            if(firstInput[j] == i && j == i){
                break;
            }else if (firstInput[j] == i){
                ++res;
                int t = j;
                while(i != t){
                    swap(firstInput[t],firstInput[t-1]);
                    --t;
                }
                break;
            }
        }
    }
    cout << res;

}
}