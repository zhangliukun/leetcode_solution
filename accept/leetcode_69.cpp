/* Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer. */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 1,high = x;
        if(x==0)return 0;
        while(true){
            int mid = (low+high)>>1;
            if(mid > x/mid){
                high = mid -1;
            }else{
                if(mid+1>x/(mid+1)){
                    return mid;
                }
                low = mid +1;
            }
        }
    }
    
};

int main()
{
    Solution s;
    cout<<s.mySqrt(2147395599);

    return 0;
}