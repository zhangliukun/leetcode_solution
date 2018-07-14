/*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.*/
#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //分治法
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size()==0)return INT_MIN;
        if(nums.size()==1)return nums[0];

        int mid = nums.size()>>1;
        vector<int> left(nums.begin(),nums.begin()+mid);
        int l = maxSubArray(left);
        int l_mid_max=nums[mid-1],l_mid=l_mid_max;
        for(int i=mid-2;i>=0;i--){

            l_mid  += nums[i];
            if(l_mid>l_mid_max){
                l_mid_max = l_mid;
            }
        }

        vector<int> right(nums.begin()+mid,nums.begin()+nums.size());
        int r = maxSubArray(right);
        
        int r_mid_max=nums[mid], r_mid=r_mid_max;
        for(int i=mid+1;i<nums.size();i++){
            r_mid += nums[i];
            if(r_mid>r_mid_max){
                r_mid_max = r_mid;
            }
        }
        cout << l <<" "<<r<<endl;

        if(l>=r && l>(l_mid_max+r_mid_max))return l;
        else if(r>=l && r>(l_mid_max+r_mid_max))return r;
        else return l_mid_max+r_mid_max; 
    } 

    //贪心法
    /* int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int max =nums[0];
        int result = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i]+result){
                result = nums[i];
            }else{
                result = nums[i]+result;
            }
            max = max > result ? max:result;
        }
        return max;
    }  */
};

int main()
{
    Solution s;
    //int num[] = {-2,1,-3,4,-1,2,1,-5,4};
    //int num[] = {1,2};
    int num[]={-1,-1,-2,-2};
    //int num[]={-2,1};
    vector<int> vc(num,num+4);
    cout<<s.maxSubArray(vc);
    return 0;
}