/* Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */
#include <iostream>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:

    int checkOverFlow(long x)
    {
        if(x>INT32_MAX || x<INT32_MIN)
        {
            return 0;
        }
        return 1;
    }

    int reverse(int x) {
        queue<int> st;
        bool flag =0;
        long result=0;
        if(checkOverFlow(x)==0)return 0;
        if(x<0)
        {
            flag = 1;
            x = -x;
        }
        while(x!=0)
        {
            st.push(x%10);
            x/=10;
        }
        while(!st.empty())
        {
            result = result*10 + st.front();
            st.pop();
        }
        result = flag == 0?result:-result;
        if(checkOverFlow(result)==0)return 0;
        return result;
    }
};

int main()
{
    Solution s;
    //printf("%d\n",s.reverse(-123));
    //printf("%d\n",s.reverse(123));
    //printf("%d\n",s.reverse(120));
    printf("%d\n",s.reverse(1534236469));
    
    return 0;
}