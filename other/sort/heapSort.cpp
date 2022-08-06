//
// Created by l1nkkk on 2021/10/1.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

namespace sortFunc{
// 大顶堆
class headSort{
public:
    headSort(vector<int>& anums):nums(anums){
        END = anums.size();
    }
    void sort(){
        // 创最大堆
        createBigHeap();
        // 将顶和最后交换，然后将顶下层
        while(END > 0){
            swap(nums[--END], nums[0]);
            sink(0);
        }
    }

private:
    void createBigHeap(){
        // 先找到第一个非叶子节点
        int node = (END-1)/2;
        while(node >= 0){
            sink(node);
            --node;
        }
    }

private:
    // 下沉
    void sink(int k){
        while(left(k) < END){
            int older = left(k);
            if(right(k) < END && nums[older] < nums[right(k)])
                older = right(k);
            if(nums[k] >= nums[older]) break;
            swap(nums[k],nums[older]);
            k = older;
        }
    }

    // 上浮
    void swim(int k){
        while(k > 0 && nums[parent(k)] < nums[k]){
            swap(nums[parent(k)], nums[k]);
            k = parent(k);
        }
    }

    inline int parent(int k){
        if(k == 0) return -1;
        return (k-1)/2;
    }
    inline int left(int k){
        return k*2+1;
    }
    inline int right(int k){
        return k*2+2;
    }

    vector<int>& nums;
    int END;
};

void testHeapSort(){
    vector<int> input{4,1,5,9,2,6,5,6,1,8,0,7};
    auto s = headSort(input);
    s.sort();
    for(auto &a : input){
        cout << a << " ";
    }

}
}