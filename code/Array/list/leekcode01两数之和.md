# 两数之和
> 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。  
>你可以假设**每种输入只会对应一个答案**。但是，你不能重复利用这个数组中同样的元素。  

> 示例:  
> 给定 nums = [2, 7, 11, 15], target = 9
> 因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

## 解法1
用i和j分别指向两个数进行遍历  
228ms 战胜31%
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int i,j;
    int len = nums.size();
    for(i = 0;i < len;i++){
        if(nums[i]>target) continue;
        for(j = i+1;j < len;j++){
            if(nums[i]+nums[j] == target){
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
        if(j != len){
            break;
        }
    }
    return res;

}
```

##解法2(优化)
12ms 战胜90%
借助map记录前面状态,且只使用一层循环,一次遍历。  
**（注：当使用两层循环的时候，往往可以使用map记录从而减少循环。）**
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int,int> m;
        int i = 0;
        int len = nums.size();

        while(i != len){
            if(m.find(nums[i]) != m.end())
                return vector<int>{m[nums[i]],i};
            // 注意这里的target - nums[i]
            m[target - nums[i]] = i;
            i++;
        }
        return vector<int>{};

    }
};
```