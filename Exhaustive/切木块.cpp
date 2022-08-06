//
// Created by l1nkkk on 12/17/20.
//
#include <vector>
#include <map>
#include <iostream>
namespace  woodcut{
    using namespace std;
    struct dealOps{
        // 用来针对当前木料对木块进行一个选择
        void dfs(int currentWood,int currentBlock){
            int i = currentBlock;
            // 终极退出,全部都选了的。被制造出来的木材数=想要被制造的木材数
            if(blockToWood.size() == block.size()) {
                res = min(res, currentWood+1);
                WoodMax = currentWood+1;
                return;
            }
            // 与目前最小的结果持平，没必要继续了
            if(currentWood+1 == WoodMax) return;
            // 已经到了currentBlock末尾了
            if(currentBlock+1 > block.size()){
                dfs(currentWood+1,0);
                return;
            }
            //if(currentBlock > block.size()) return;
            // 当前木块已经被选了
            if(blockToWood.find(currentBlock) !=blockToWood.end()){
                goto NOSELECT;
            }
            // 1.如果没有被选，可选可不选
            // 1.1 选
            // 1.1.1 先看看够不够
            if(woodUse[currentWood] >= block[currentBlock]) {
                blockToWood[currentBlock] = currentWood;
                woodUse[currentWood] =woodUse[currentWood] - block[currentBlock] - sawLen;


                dfs(currentWood, currentBlock+1);
                blockToWood.erase(currentBlock);
                woodUse[currentWood] =woodUse[currentWood] + block[currentBlock] + sawLen;
            }
            NOSELECT:
            // 1.2 不选
            dfs(currentWood, currentBlock+1);
        }
        // leftLen:为currentWood木料剩下的
        int operator ()(){
            dfs(0,0);
            return res;
        }

        dealOps(int wl,int sl,const vector<int>& bk):woodLen(wl),sawLen(sl),block(bk){
            WoodMax = res = block.size();// 结果最多就为block.size()
            for(int i = 0;i < WoodMax; ++i){
                woodUse[i] = woodLen;
            }


        }
    public:
        // 木料最大可能数，等于木块的数量
        int WoodMax;
        map<int,int> woodUse; // 木料使用情况，剩余的
        // 存储用户输入，需要做成的木块
        vector<int> block;
        map<int,int> blockToWood; // 表示指向木块是通过哪块木料切割而成的
        int sawLen; // 锯子宽度
        int woodLen; // 木料宽度
        int res; // 将其初始化为最大
    };

    void test(){
        //auto d = dealOps(1000,100,{200,1000});
        auto d = dealOps(1000,100,{200,200,200,300,300,400});
        //auto d = dealOps(1000,100,{200,200,300,400,600});
        cout << d();
    }
}