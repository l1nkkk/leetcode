//
// Created by l1nkkk on 2022/3/27.
//

#include <iostream>
#include <vector>
using namespace std;
namespace offer33{
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() == 0) return true;
        int ma = postorder[0],mi = postorder[0];
        for(auto a :postorder){
            ma = ma < a ? a : ma;
            mi = mi > a ? a : mi;
        }
        return check(postorder, 0, postorder.size(), mi, ma);
    }

    // 判断，并划分子树.[lo,hi)
    bool check(vector<int>& nums, int lo, int hi, int start, int limit){
        if(lo >= hi) return true;
        int root = hi-1;
        if(nums[root] > limit || nums[root] < start) return false;

        int split = root-1;
        while(split >= 0 && nums[split] > nums[root]){
            if(nums[split] > limit || nums[split] < start) return false;
            --split;
        }

        return check(nums, lo, split+1, start, nums[root]-1)
            && check(nums, split+1, root, nums[root]+1, limit);
    }
};

void test(){
    Solution s;
    vector<int> input1{1,6,3,2,5};
    vector<int> input2{1,3,2,6,5};
    cout << s.verifyPostorder(input1) << endl;
    cout << s.verifyPostorder(input2) << endl;
}

}