#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator it;
        vector<int>::iterator it2;
        for(it = nums.begin();it!=nums.end()-1;it++)
        {
            for(it2 = it+1;it2!=nums.end();it2++)
            {
                if((*it + *it2)==target)
                {
                    //printf("%ld %ld",it- nums.begin(), it2 - nums.begin());
                    vector<int> vc;
                    vc.push_back(it- nums.begin());
                    vc.push_back(it2 - nums.begin());                    
                    return vc;
                }
            }
        }
        return nums;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(11);
    nums.push_back(7);
    nums.push_back(15);
    Solution s;
    s.twoSum(nums,9);



    

    return 0;
}