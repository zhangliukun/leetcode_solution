/* Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 */

/* Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length. */
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //时间复杂度O(n^2)
        /* int size = nums.size();
        for(int i=0;i<size-1;)
        {
            if(nums[i] == nums[i+1])
            {
                for(int j=i+1;j<size-1;j++)
                {
                    nums[j] = nums[j+1];
                }
                size --;
            }else{
                i++;
            }
        }
        return size; */
        //时间复杂度O(n)
        int size = nums.size();
        int j=0;
        for(int i=1;i<size;i++)
        {
            if(nums[j] != nums[i])
            {
                j++;
                nums[j] = nums[i];
            }
        }
        return size ==0?size : j+1;
    }
    
};

int main()
{

    Solution s;
    int n[] = {1,1,2,3,3};
    vector<int> nums(n,n+5);
    cout<< s.removeDuplicates(nums);



    return 0;
}