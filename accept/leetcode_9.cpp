//Determine whether an integer is a palindrome. Do this without extra space.
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

class Solution {
public:
    int getLength(int x)
    {
        int count=0;
        while(x!=0)
        {
            x /=10;
            count++;
        }
        return count;
    }
    int getNum(int x,int divide)
    {
        x = x / pow((double)10,divide);
        return x%10;
    }
    bool isPalindrome(int x) {
        if(x<0)return false;
        int length = getLength(x);
        for(int i=0;i<length/2;i++)
        {
            if(getNum(x,i) != getNum(x,length-i-1))
            {
                return false;
            }
        }
        return true;
    }
    
};

int main()
{
    Solution s;
    printf("%d\n",s.isPalindrome(123123));
    printf("%d\n",s.isPalindrome(12321));
    
    return 0;
}