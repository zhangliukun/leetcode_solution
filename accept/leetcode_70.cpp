/* You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer. */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:

    
    int climbStairs(int n) {
        vector<int> nums(n,0);
        return climb(0,n,nums);
    }

    //递归剪枝
    int climb(int x,int n,vector<int> &nums){
        if(x>n){
            return 0;
        }
        if(x==n){
            return 1;
        }
        if(nums[x]>0)return nums[x];
        nums[x] = climb(x+1,n,nums)+climb(x+2,n,nums);
        return nums[x];
    }

    int climbStairs_dy(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    
};

int main()
{
    Solution s;
    cout << s.climbStairs(44)<<endl;
    cout<< s.climbStairs_dy(6);

    return 0;
}