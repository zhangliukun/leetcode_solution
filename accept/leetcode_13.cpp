/* Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
I - 1
V - 5
X - 10
L - 50
C - 100
D - 500
M - 1000 */
#include <iostream>
#include <map>
#include <limits>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> num;
        num.insert(make_pair('I',1));
        num.insert(make_pair('V',5));
        num.insert(make_pair('X',10));
        num.insert(make_pair('L',50));
        num.insert(make_pair('C',100));
        num.insert(make_pair('D',500));
        num.insert(make_pair('M',1000));
        
        map<char,int>::iterator iter;
        int length = s.length();
        int result =0;
        int lastNum = INT32_MAX;
        for(int i=length-1;i>=0;i--)
        {
            iter =  num.find(s[i]);
            if(i == length -1 )
            {   
                lastNum = iter->second;       
                result += lastNum;
            }else
            {
                if(iter->second >= lastNum)
                {
                    result += iter->second;
                }else
                {
                    result -= iter->second;
                }
                lastNum = iter->second;
            }
        }
        return result;
    }
    
};

int main()
{
    Solution s;
    printf("%d",s.romanToInt("XLV"));
    return 0;
}