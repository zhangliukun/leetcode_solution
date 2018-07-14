/* Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1*/
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:

    int strStr(string haystack, string needle) {
        if(haystack.empty()&&needle.empty())return 0;
        if(haystack.length()<needle.length())return -1;
        for(int i=0;i<haystack.length()-needle.length()+1;i++)
        {
            int j=0;
            int nsize = needle.length();
            for(;j<nsize;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
            }
            if(j == nsize){
                return i;
            }
        }
        return -1;
    }
    
};

int main()
{
    Solution s;
    cout<< s.strStr("","");


    return 0;
}