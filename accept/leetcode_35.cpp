/* Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
Input: [1,3,5,6], 5
Output: 2*/
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:

    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        if(target>nums[high]) return high+1;
        if(target<nums[low]) return low;
        int mid=0;
        while(low<=high){
            mid = (low+high)>>1;
            if(nums[mid]<target){
                low = mid+1;
            }else if(nums[mid]>target){
                high = mid-1;
            }else{
                return mid;
            }
        }
        return low;
    }
    
};

int main()
{
    Solution s;
    int num[] = {1,3,5,8};
    vector<int> vc(num,num+4);
    cout<< s.searchInsert(vc,4);

    return 0;
}