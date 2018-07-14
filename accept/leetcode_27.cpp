/* Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2. */
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int flag = 0;
        int i,j =0;
        if(size == 1 && val == nums[0]) return 0;
        for(i=0,j=size -1;i<=j;) {
            if(flag == 0){
                if(nums[i] != val){
                    i++;
                }else{
                    flag = 1;
                }
            }else{
                if(nums[j] != val){
                    nums[i] = nums[j];
                    j--;
                    i++;
                    flag =0;
                }else{
                    j--;
                }
            }
            
        }
        return j+1;
    }
    
};

int main()
{
    Solution s;
    int num[]={3,3};
    vector<int> vc(num,num+2);
    cout<<s.removeElement(vc,3);


    return 0;
}