//
// Created by l1nkkk on 2021/7/5.
//
#include <vector>
#include <iostream>
using namespace std;

namespace leetcode300{
    class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> dp(nums.size(),1);
            int max = 1;
            for(int i = 1; i < nums.size(); ++i){
                // find min
                int j = i-1;
                while(j >= 0 ){
                    if( nums[i] > nums[j] && dp[j] > dp[i]-1)
                        dp[i] = dp[j]+1;
                    --j;
                }
                max = dp[i] > max ? dp[i] : max;
            }
            return max;
        }

    };
    class Solution2 {
    public:
        int lengthOfLIS(vector<int>& nums) {
            // 记录牌堆的顶端
            vector<int> topVec(3000, -10001);
            int res = 0;
            int end = res;
            int start = 0;

            for(int i = 0; i < nums.size(); ++i){
                /* 二分法 start  */
                start = 0;
                end  = res;

                while(start < end){
                    int mid = (start + end)/2;
                    if(topVec[mid] > nums[i])
                        end = mid;
                    else if (topVec[mid] < nums[i])
                        start = mid+1;
                    else
                        end = mid;
                }
                if(start == res)
                    res++;
                //
                topVec[start] = nums[i];
                /* 二分法 end  */
            }
            return res;
        }
    };
    void test(){
        Solution s;
        vector<int> vi = {0,1,0,3,2,3};
        cout << s.lengthOfLIS(vi);
    }
}